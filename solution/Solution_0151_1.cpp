class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int slow = 0, fast = 0;
        
        // 1. 移除多餘空白（原地清理）
        while (fast < n) {
            // 跳過所有空白
            while (fast < n && s[fast] == ' ') fast++;
            // 如果已經到底了就跳出
            if (fast == n) break;
            // 如果不是第一個單字，補一個空格隔開
            if (slow != 0) s[slow++] = ' ';
            // 複製單字的字母
            while (fast < n && s[fast] != ' ') {
                s[slow++] = s[fast++];
            }
        }
        // 縮減字串大小，去掉尾端多餘的長度
        s.resize(slow);
        
        // 2. 把整個清理好的字串大反轉
        reverse(s.begin(), s.end());
        
        // 3. 把每一個單字個別反轉回來
        int start = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        
        return s;
    }
};