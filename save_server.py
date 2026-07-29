#!/usr/bin/env python3
"""
save_server.py — 本機小伺服器：
  - 提供 solution-generator.html 的靜態頁面
  - 接受 POST /api/save，直接把 metadata/*.yml 與 solution/*.cpp
    寫進本機資料夾（不透過瀏覽器的檔案系統權限，避免 \\wsl$ 網路磁碟權限問題）
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

METADATA_DIR = "metadata"
SOLUTION_DIR = "solution"
PUBLISH_SCRIPT = "publish.sh"
PUBLISH_TIMEOUT_SEC = 180

SAFE_FILENAME_RE = re.compile(r'^[A-Za-z0-9_\-\.]+$')
ANSI_RE = re.compile(r'\x1b\[[0-9;]*m')

def is_safe_filename(name):
    return bool(name) and SAFE_FILENAME_RE.match(name) and '..' not in name


class Handler(http.server.SimpleHTTPRequestHandler):

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
        if self.path == '/api/save':
            self._handle_save()
        elif self.path == '/api/publish':
            self._handle_publish()
        else:
            self._send_json(404, {'error': 'not found'})

    def _handle_save(self):
        try:
            data = self._read_json_body()
        except Exception as e:
            self._send_json(400, {'error': f'無法解析請求內容: {e}'})
            return

        saved = []
        errors = []

        meta = data.get('metadata')
        if meta:
            fname = meta.get('filename', '')
            content = meta.get('content', '')
            if not is_safe_filename(fname):
                errors.append(f'metadata 檔名不合法: {fname}')
            else:
                os.makedirs(METADATA_DIR, exist_ok=True)
                path = os.path.join(METADATA_DIR, fname)
                with open(path, 'w', encoding='utf-8') as f:
                    f.write(content)
                saved.append(f'{METADATA_DIR}/{fname}')

        for sol in data.get('solutions', []):
            fname = sol.get('filename', '')
            content = sol.get('content', '')
            if not is_safe_filename(fname):
                errors.append(f'.cpp 檔名不合法: {fname}')
                continue
            os.makedirs(SOLUTION_DIR, exist_ok=True)
            path = os.path.join(SOLUTION_DIR, fname)
            with open(path, 'w', encoding='utf-8') as f:
                f.write(content)
            saved.append(f'{SOLUTION_DIR}/{fname}')

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

        try:
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

    def log_message(self, format, *args):
        # 精簡一點的 log，只顯示方法與路徑
        sys.stderr.write(f"{self.command} {self.path} -> {args[1] if len(args) > 1 else ''}\n")


def main():
    port = int(sys.argv[1]) if len(sys.argv) > 1 else 8090
    server = http.server.HTTPServer(('localhost', port), Handler)
    print(f"✓ 伺服器啟動: http://localhost:{port}/solution-generator.html")
    print(f"  metadata 會寫進: ./{METADATA_DIR}/")
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
