/**
 * 題目：2109. Adding Spaces to a String (向字串添加空格)
 * 難度：中等 (Medium)
 * 描述：在給定的空間索引處插入空格，並回傳新的字串。
 * * 時間複雜度：O(N + M) - N 為字串長度，M 為 spaces 陣列長度。
 * 空間複雜度：O(N + M) - 用於儲存最終產生的字串。
 * * 解法思路：
 * 1. 使用 `res` 字串存放結果。為了效能，使用 `reserve()` 預先分配足夠空間。
 * 2. 使用指標 `j` 追蹤 `spaces` 陣列的索引，`i` 追蹤原字串 `s` 的索引。
 * 3. 遍歷過程中，若 `i` 達到 `spaces[j]` 的位置，則先加入空格並移動 `j`。
 * 4. 最後加入當前字元 `s[i]`。
 */

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res;
        // 效能優化：預先分配空間，避免 res 在過程中不斷動態擴充記憶體
        res.reserve(s.size() + spaces.size());
        
        int j = 0; // 用於遍歷 spaces 的指標
        for (int i = 0; i < s.size(); ++i) {
            // 如果當前索引符合空格位置，插入空格
            if (j < spaces.size() && i == spaces[j]) {
                res += ' ';
                j++;
            }
            // 放入原字串的字元
            res += s[i];
        }
        
        return res;
    }
};
