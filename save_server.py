#!/usr/bin/env python3
"""
save_server.py — 本機小伺服器：
  - 提供 solution-generator.html 的靜態頁面
  - 接受 POST /api/save，直接把 metadata/*.yml 與 solution/*.cpp
    寫進本機資料夾（不透過瀏覽器的檔案系統權限，避免 \\wsl$ 網路磁碟權限問題）

用法（在 repo 根目錄執行）：
    python3 save_server.py 8090

然後用 Chrome/Edge 打開：
    http://localhost:8090/solution-generator.html
"""
import http.server
import json
import os
import sys
import re

METADATA_DIR = "metadata"
SOLUTION_DIR = "solution"

SAFE_FILENAME_RE = re.compile(r'^[A-Za-z0-9_\-\.]+$')

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

    def do_POST(self):
        if self.path != '/api/save':
            self._send_json(404, {'error': 'not found'})
            return

        try:
            length = int(self.headers.get('Content-Length', 0))
            raw = self.rfile.read(length)
            data = json.loads(raw.decode('utf-8'))
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

    def log_message(self, format, *args):
        # 精簡一點的 log，只顯示方法與路徑
        sys.stderr.write(f"{self.command} {self.path} -> {args[1] if len(args) > 1 else ''}\n")


def main():
    port = int(sys.argv[1]) if len(sys.argv) > 1 else 8090
    server = http.server.HTTPServer(('localhost', port), Handler)
    print(f"✓ 伺服器啟動: http://localhost:{port}/solution-generator.html")
    print(f"  metadata 會寫進: ./{METADATA_DIR}/")
    print(f"  solution 會寫進: ./{SOLUTION_DIR}/")
    print("  按 Ctrl+C 停止")
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        print("\n已停止")


if __name__ == '__main__':
    main()
