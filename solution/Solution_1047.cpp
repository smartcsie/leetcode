/**
 * 題目：1047. Remove All Adjacent Duplicates In String (刪除字串中的所有相鄰重複項)
 * 難度：簡單 (Easy)
 * 描述：給出由小寫字母組成的字串 S，重複項刪除操作會選擇兩個相鄰且相同的字母並刪除它們。
 *      在 S 上反復執行重複項刪除操作，直到無法繼續刪除為止。
 * 
 * 時間複雜度：O(n) - 遍歷一次字串，每個字元最多進出「堆疊」一次。
 * 空間複雜度：O(n) - 最壞情況下（無重複）需要存儲整個字串。
 * 
 * 解法思路：
 * 1. 核心機制是「匹配與消除」，這與「有效的括號」邏輯完全一致。
 * 2. 使用一個字串 `res` 作為輔助堆疊 (Stack)：
 *    - 遍歷原字串中的每個字元 `c`。
 *    - 若堆疊不為空且 `c` 等於堆疊頂端的元素，說明發現了「相鄰重複項」。
 *    - 此時將堆疊頂端元素彈出 (pop_back)，代表這對重複項被抵消了。
 *    - 否則，將 `c` 壓入堆疊 (push_back)。
 * 3. 最終堆疊中留下的就是消除後的結果。
 */

class Solution {
public:
    string removeDuplicates(string s) {
        // 直接使用 string 作為 stack，避免額外的資料結構轉換
        string res = "";
        for (char c : s) {
            // 如果結果字串不為空，且當前字元與最後一個放入的字元相同
            if (!res.empty() && c == res.back()) {
                // 發現相鄰重複，消除（彈出）
                res.pop_back();
            } else {
                // 不相同或堆疊為空，放入
                res.push_back(c);
            }
        }
        return res;
    }
};
