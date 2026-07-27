/**
 * 題目：3798. Largest Even Number
 * 難度：簡單 (Easy)
 * 描述：在僅含 '1' 和 '2' 的字串中，刪除部分字元（保持順序）以構成最大的偶數。
 * * 時間複雜度：O(N) - 使用 rfind 掃描字串一次。
 * 空間複雜度：O(1) - 若不計回傳的字串長度，額外空間為常數級別。
 * * 優化思路：
 * 1. 偶數判定：題目字元僅有 '1' 與 '2'，構成偶數的唯一條件是末位為 '2'。
 * 2. 最大化策略：若要使數值最大，應保留儘量多的位數。
 * 3. 貪婪邏輯：截取到最後一個 '2' 的位置，即可保留該字元前的所有位數，確保長度與數值最大化。
 */

class Solution {
public:
    string largestEven(string s) {
        size_t last_two = s.rfind('2');
        return last_two == string::npos ? "" : s.substr(0, last_two + 1);
    }
};
