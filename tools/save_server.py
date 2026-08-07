#!/usr/bin/env python3
"""
save_server.py — 本機小伺服器：
  - 提供 solution-generator.html 的靜態頁面
  - 接受 POST /api/save，把 metadata/*.yml 與 solution/*.cpp 寫進本機資料夾
    （不透過瀏覽器的檔案系統權限，避免 \\wsl$ 網路磁碟權限問題）
    若該題號的 metadata 檔案已存在，會與既有的 solutions 合併
    （同檔名覆蓋更新、不同檔名新增為額外解法變體），不會整份覆蓋掉。
  - 接受 POST /api/publish，執行同資料夾下的 publish.sh
    （generate_site.py + git commit/push + mkdocs gh-deploy）

用法（在 repo 根目錄執行，需與 publish.sh 放在同一層）：
    python3 save_server.py 8090

然後用 Chrome/Edge 打開：
    http://localhost:8090/solution-generator.html
"""
import http.server
import json
import os
import sys
import re
import subprocess
import threading
import time

try:
    import yaml
except ImportError:
    print("需要 PyYAML，請先執行: pip install pyyaml --break-system-packages")
    sys.exit(1)

METADATA_DIR = "metadata"
SOLUTION_DIR = "solution"
PUBLISH_SCRIPT = "publish.sh"
PUBLISH_TIMEOUT_SEC = 180


def load_activation_code():
    """
    密碼放在 activation_code.txt（不會被 git 追蹤，見 .gitignore），
    不寫死在這個檔案裡，因為 save_server.py 本身可能被 push 到 public repo。
    找不到設定檔就用一個永遠不會通過驗證的預設值，安全失敗（fail closed）。
    """
    path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'activation_code.txt')
    if os.path.exists(path):
        with open(path, 'r', encoding='utf-8') as f:
            code = f.read().strip()
        if code:
            return code
    print("⚠️  警告：找不到 activation_code.txt，或內容是空的！")
    print("⚠️  目前使用無效的預設密碼，所有存檔/發佈請求都會被拒絕。")
    print("⚠️  請在 save_server.py 同一層資料夾建立 activation_code.txt，內容填入你自己的密碼。")
    return "PLEASE-SET-activation_code.txt-" + os.urandom(8).hex()


# ⚠️ 真正的密碼放在同層資料夾的 activation_code.txt（已加進 .gitignore，不會被 push 上去）
ACTIVATION_CODE = load_activation_code()

# 發佈鎖：避免上一次 publish.sh 還沒跑完，就又被觸發第二次
# （這是之前造成 GitHub Pages 部署互相卡住、逾時失敗的主因）
publish_lock = threading.Lock()
publish_started_at = None

SAFE_FILENAME_RE = re.compile(r'^[A-Za-z0-9_\-\.]+$')
ANSI_RE = re.compile(r'\x1b\[[0-9;]*m')


def is_safe_filename(name):
    return bool(name) and SAFE_FILENAME_RE.match(name) and '..' not in name


def save_metadata_and_code(meta_dir, solution_dir, number, title, url, incoming_solutions):
    """
    合併寫入：若 metadata/{number}.yml 已存在，讀出既有 solutions，
    依照 'file' 欄位比對：同檔名 -> 覆蓋更新；不同檔名 -> 新增變體。
    回傳 (saved_paths, errors)
    """
    os.makedirs(meta_dir, exist_ok=True)
    os.makedirs(solution_dir, exist_ok=True)

    meta_path = os.path.join(meta_dir, f"{number:04d}.yml")
    saved = []
    errors = []

    existing_solutions = []
    if os.path.exists(meta_path):
        try:
            with open(meta_path, 'r', encoding='utf-8') as f:
                existing_data = yaml.safe_load(f) or {}
            existing_solutions = existing_data.get('solutions', []) or []
        except Exception as e:
            errors.append(f'讀取既有 metadata 失敗，將視為新檔案處理: {e}')

    by_file = {s.get('file'): s for s in existing_solutions if s.get('file')}
    order = [s.get('file') for s in existing_solutions if s.get('file')]

    for sol in incoming_solutions:
        fname = sol.get('file', '')
        if not is_safe_filename(fname):
            errors.append(f'.cpp 檔名不合法: {fname}')
            continue

        code = sol.pop('code', None)
        if not sol.get('familiarity'):
            sol.pop('familiarity', None)
        if not sol.get('note'):
            sol.pop('note', None)
        if not sol.get('is_best'):
            sol.pop('is_best', None)
        if not sol.get('related'):
            sol.pop('related', None)

        if fname not in by_file:
            order.append(fname)
        by_file[fname] = sol

        if code is not None:
            cpp_path = os.path.join(solution_dir, fname)
            with open(cpp_path, 'w', encoding='utf-8') as f:
                f.write(code)
            saved.append(f'{solution_dir}/{fname}')

    merged_solutions = [by_file[f] for f in order if f in by_file]

    meta_out = {
        'number': number,
        'title': title,
        'url': url,
        'solutions': merged_solutions,
    }
    with open(meta_path, 'w', encoding='utf-8') as f:
        yaml.dump(meta_out, f, allow_unicode=True, sort_keys=False)
    saved.insert(0, f'{meta_dir}/{number:04d}.yml')

    return saved, errors


class Handler(http.server.SimpleHTTPRequestHandler):

    def _check_auth(self):
        provided = self.headers.get('X-Activation-Code', '')
        return provided == ACTIVATION_CODE

    def _send_json(self, status, payload):
        body = json.dumps(payload, ensure_ascii=False).encode('utf-8')
        self.send_response(status)
        self.send_header('Content-Type', 'application/json; charset=utf-8')
        self.send_header('Content-Length', str(len(body)))
        self.end_headers()
        self.wfile.write(body)

    def _read_json_body(self):
        length = int(self.headers.get('Content-Length', 0))
        raw = self.rfile.read(length) if length else b''
        return json.loads(raw.decode('utf-8')) if raw else {}

    def do_POST(self):
        if not self._check_auth():
            self._send_json(401, {'error': '啟用碼錯誤或未提供，請確認網頁上方「啟用碼」欄位'})
            return
        if self.path == '/api/save':
            self._handle_save()
        elif self.path == '/api/publish':
            self._handle_publish()
        else:
            self._send_json(404, {'error': 'not found'})

    def do_GET(self):
        if self.path.startswith('/api/problem/'):
            if not self._check_auth():
                self._send_json(401, {'error': '啟用碼錯誤或未提供，請確認網頁上方「啟用碼」欄位'})
                return
            self._handle_load_problem()
        else:
            super().do_GET()

    def _handle_load_problem(self):
        raw_number = self.path.rsplit('/', 1)[-1]
        try:
            number = int(raw_number)
        except ValueError:
            self._send_json(400, {'error': f'題號格式錯誤: {raw_number!r}'})
            return

        meta_path = os.path.join(METADATA_DIR, f"{number:04d}.yml")
        if not os.path.exists(meta_path):
            self._send_json(404, {'error': f'找不到題目 {number}（metadata/{number:04d}.yml 不存在）'})
            return

        try:
            with open(meta_path, 'r', encoding='utf-8') as f:
                data = yaml.safe_load(f) or {}
        except Exception as e:
            self._send_json(500, {'error': f'讀取 metadata 失敗: {e}'})
            return

        solutions = data.get('solutions', []) or []
        for sol in solutions:
            fname = sol.get('file', '')
            code = ''
            if fname and is_safe_filename(fname):
                cpp_path = os.path.join(SOLUTION_DIR, fname)
                if os.path.exists(cpp_path):
                    with open(cpp_path, 'r', encoding='utf-8', errors='replace') as f:
                        code = f.read()
            sol['code'] = code

        self._send_json(200, {
            'number': data.get('number', number),
            'title': data.get('title', ''),
            'url': data.get('url', ''),
            'solutions': solutions,
        })

    def _handle_save(self):
        try:
            data = self._read_json_body()
        except Exception as e:
            self._send_json(400, {'error': f'無法解析請求內容: {e}'})
            return

        number = data.get('number')
        try:
            number = int(number)
        except (TypeError, ValueError):
            self._send_json(400, {'error': f'題號格式錯誤或缺少題號: {number!r}'})
            return

        title = data.get('title', '')
        url = data.get('url', '')
        incoming_solutions = data.get('solutions', [])

        try:
            saved, errors = save_metadata_and_code(
                METADATA_DIR, SOLUTION_DIR, number, title, url, incoming_solutions
            )
        except Exception as e:
            self._send_json(500, {'error': f'存檔時發生錯誤: {e}'})
            return

        if errors and not saved:
            self._send_json(400, {'error': '; '.join(errors)})
        else:
            self._send_json(200, {'status': 'ok', 'saved': saved, 'errors': errors})

    def _handle_publish(self):
        try:
            data = self._read_json_body()
        except Exception as e:
            self._send_json(400, {'error': f'無法解析請求內容: {e}'})
            return

        message = (data.get('message') or '').strip()
        if not message:
            self._send_json(400, {'error': '請提供 commit 訊息'})
            return

        script_path = os.path.join(os.getcwd(), PUBLISH_SCRIPT)
        if not os.path.exists(script_path):
            self._send_json(400, {'error': f'找不到 {script_path}，請確認 {PUBLISH_SCRIPT} 跟 save_server.py 放在同一個資料夾'})
            return

        global publish_started_at

        # 非阻塞方式取得鎖：如果已經有一個 publish 在跑，直接回報，不要排隊等、
        # 更不要真的同時跑第二個 publish.sh（那正是之前造成 GitHub Pages 部署卡住的原因）
        acquired = publish_lock.acquire(blocking=False)
        if not acquired:
            elapsed = int(time.time() - publish_started_at) if publish_started_at else None
            elapsed_str = f'（已執行約 {elapsed} 秒）' if elapsed is not None else ''
            self._send_json(409, {
                'error': f'已經有一個發佈正在進行中{elapsed_str}，請等它完成後再試一次，不要重複按「發佈」',
            })
            return

        try:
            publish_started_at = time.time()
            result = subprocess.run(
                ['bash', script_path, message],
                cwd=os.getcwd(),
                capture_output=True,
                text=True,
                timeout=PUBLISH_TIMEOUT_SEC,
            )
            output = result.stdout + (('\n' + result.stderr) if result.stderr else '')
            output = ANSI_RE.sub('', output)
            self._send_json(200, {
                'status': 'ok' if result.returncode == 0 else 'error',
                'returncode': result.returncode,
                'output': output,
            })
        except subprocess.TimeoutExpired as e:
            partial = (e.stdout or '') + (e.stderr or '')
            self._send_json(504, {
                'error': f'執行逾時（超過 {PUBLISH_TIMEOUT_SEC} 秒），請到終端機檢查狀況',
                'output': ANSI_RE.sub('', partial),
            })
        except Exception as e:
            self._send_json(500, {'error': str(e)})
        finally:
            publish_started_at = None
            publish_lock.release()

    def log_message(self, format, *args):
        sys.stderr.write(f"{self.command} {self.path} -> {args[1] if len(args) > 1 else ''}\n")


def main():
    port = int(sys.argv[1]) if len(sys.argv) > 1 else 8090
    server = http.server.HTTPServer(('localhost', port), Handler)
    print(f"✓ 伺服器啟動: http://localhost:{port}/solution-generator.html")
    print(f"  metadata 會寫進: ./{METADATA_DIR}/（同題號會自動合併解法變體）")
    print(f"  solution 會寫進: ./{SOLUTION_DIR}/")
    if os.path.exists(PUBLISH_SCRIPT):
        print(f"  ✓ 找到 {PUBLISH_SCRIPT}，發佈按鈕可以使用")
    else:
        print(f"  ⚠ 找不到 {PUBLISH_SCRIPT}，發佈按鈕會失敗（請確認放在同一資料夾）")
    print("  按 Ctrl+C 停止")
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        print("\n已停止")


if __name__ == '__main__':
    main()
