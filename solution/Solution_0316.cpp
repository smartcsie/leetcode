/**
 * 題目：316. Remove Duplicate Letters (去除重複字母)
 * 難度：中等 (Medium)
 * 描述：在保持原始相對順序的情況下，去除重複字母，並使結果字串字典序最小。
 * * 時間複雜度：O(N) - 每個字元最多進出堆疊一次。
 * 空間複雜度：O(1) - 陣列大小固定為 256 (ASCII 範圍)。
 * * 優化思路：
 * 1. 使用 `m` 統計每個字元剩餘的數量。
 * 2. 使用 `visited` 追蹤字元是否已在堆疊中。
 * 3. 若當前字元比堆疊頂部小，且堆疊頂部字元在後面還會出現，則將堆疊頂部彈出，以維持字典序最小。
 */

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int count[256] = {0};       // 記錄字元總剩餘數
        bool inStack[256] = {false}; // 記錄字元是否在堆疊中
        string res = "0";          // 使用 "0" 作為哨兵避免判斷 res.empty()
        
        for (unsigned char c : s) ++count[c];
        
        for (unsigned char c : s) {
            --count[c];
            
            // 若該字元已在結果中，跳過
            if (inStack[c]) continue;
            
            // 維護單調遞增棧：如果當前字元比堆疊頂部小，且堆疊頂部在後面還會出現
            while (c < res.back() && count[res.back()] > 0) {
                inStack[res.back()] = false;
                res.pop_back();
            }
            
            // 加入當前字元
            res += c;
            inStack[c] = true;
        }
        
        return res.substr(1); // 移除哨兵 "0"
    }
};
