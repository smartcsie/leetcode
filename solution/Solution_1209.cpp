/**
 * 題目：1209. Remove All Adjacent Duplicates in String II (刪除字串中的所有相鄰重複項 II)
 * 難度：中等 (Medium)
 * 描述：給你一個字串 s 和一個整數 k，請你反復執行以下操作：選擇 s 中 k 個相鄰且相同的字母並刪除。
 *      在無法繼續刪除後，返回最終結果。
 * 
 * 時間複雜度：O(n) - 遍歷一次字串，每個元素最多進出堆疊一次。
 * 空間複雜度：O(n) - 最壞情況下堆疊需要存儲所有字元。
 * 
 * 解法思路：
 * 1. 核心工具：使用 Stack (堆疊) 來紀錄遍歷過程中的狀態。
 * 2. 狀態壓縮：堆疊中不直接存字元，而是存儲一個 pair<char, int>，
 *    代表 {當前字元, 該字元連續出現的次數}。
 * 3. 遍歷逻辑：
 *    - 若當前字元 c 與堆疊頂部的字元相同，則將次數加 1。
 *    - 若不相同，則將 {c, 1} 壓入堆疊。
 *    - 壓入或累加後，檢查堆疊頂部的次數是否等於 k。
 *    - 若等於 k，直接彈出該對 (pop_back)，代表這 k 個字元被「抵消」了。
 * 4. 結果重組：遍歷結束後，根據堆疊中剩餘的字元與次數，重組回字串。
 */

class Solution {
public:
    string removeDuplicates(string s, int k) {
        // 使用 vector 作為堆疊，存儲 {字元, 連續次數}
        vector<pair<char, int>> st;
        for (char c : s) {
            if (!st.empty() && st.back().first == c) {
                // 如果當前字元與棧頂相同，累加次數
                st.back().second++;
            } else {
                // 否則，作為新字元壓入，次數設為 1
                st.push_back({c, 1});
            }
            // 關鍵：一旦次數達到 k，立即將該組消除
            if (st.back().second == k) {
                st.pop_back();
            }
        }
        // 根據堆疊剩餘狀態重組字串
        string res = "";
        for (auto &element : st) {
            // 將字元按照次數 append 到結果字串
            res.append(element.second, element.first);
        }
        return res;
    }
};
