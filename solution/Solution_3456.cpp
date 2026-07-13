/**
 * 題目：3456. Find Special Substring of Length K
 * 難度：簡單 (Easy)
 * 描述：判斷是否存在一個長度恰好為 k 的連續相同字元子字串。
 * * 優化重點：
 * 1. O(N) 時間：每個字元最多被訪問兩次，線性掃描效率極高。
 * 2. 區塊思維：直接計算區塊長度，避免了繁瑣的狀態機轉移。
 */

class Solution {
public:
    bool hasSpecialSubstring(std::string s, int k) {
        int n = s.length();
        // 遍歷所有區塊
        for (int left = 0; left < n;) {
            int right = left + 1;
            
            // 找到當前連續相同字元的區塊末端
            while (right < n && s[right] == s[left]) {
                ++right;
            }
            
            // 檢查長度是否剛好為 K
            if (right - left == k) {
                return true;
            }
            
            // 直接跳到下一個不同字元的區塊
            left = right;
        }
        return false;
    }
};
