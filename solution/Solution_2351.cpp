/**
 * 題目：2351. First Letter to Appear Twice (第一個出現兩次的字母)
 * 難度：簡單 (Easy)
 * 描述：在字串中找出第一個出現兩次的字元。
 * * 時間複雜度：O(N) - N 為字串長度，最壞情況掃描完整個字串。
 * 空間複雜度：O(1) - 使用長度為 26 的固定陣列，不隨輸入大小改變。
 * * 優化思路：
 * 由於字元僅限小寫英文字母，使用 `int[26]` 取代 `unordered_map` 可以省去雜湊運算，
 * 顯著提升執行效能並降低記憶體佔用。
 */

class Solution {
public:
    char repeatedCharacter(string s) {
        // 使用一個長度為 26 的陣列記錄出現次數，並確保初始化為 0
        int count[26] = {0}; 
        
        for (const char& c : s) {
            // 將字元映射到 0-25 的索引
            int index = c - 'a';
            
            // 如果該字元已經出現過一次，說明這是第一次出現兩次的字元
            if (count[index] == 1) {
                return c;
            }
            
            // 標記字元已出現
            count[index]++;
        }
        
        return ' '; // 題目保證一定有重複字元，此行理論上不會執行
    }
};
