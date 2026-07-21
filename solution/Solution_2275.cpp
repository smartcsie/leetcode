/**
 * 題目：2275. Largest Combination With Bitwise AND Greater Than Zero
 * 描述：給定一個正整數陣列 candidates。你可以從中選出任意個數組成組合，
 *       要求組合中所有數字進行按位與 (AND) 運算的結果大於 0。
 *       請返回滿足條件的最大組合大小。
 * 
 * 解法思路：
 * 1. 核心觀念：要讓一組數字的 AND 運算結果大於 0，這群數字的二進位表示法中，
 *    「至少必須有一個相同的位元 (Bit Position) 全部都是 1」。
 * 2. 統計位元：題目給定的數字最大到 10^7（小於 2^24），
 *    因此我們只需要檢查從第 0 位到第 24 位。
 * 3. 雙重迴圈：
 *    - 外層迴圈枚舉每一個二進位位元 i（從 0 到 24）。
 *    - 內層迴圈統計 candidates 中有多少個數字在第 i 位上是 1。
 * 4. 取最大值：所有位元統計出來的數量中，取最大值即為答案。
 */

class Solution {
public:
    int largestCombination(std::vector<int>& candidates) {
        int bits = 24; // 題目數字上限 10^7 大約在 2^24 以內
        int ans = 0;
        // 枚舉每一個二進位位元
        for (int i = 0; i <= bits; i++) {
            int count = 0;
            // 計算當前位元為 1 的數字個數
            for (const int& num : candidates) {
                if ((num >> i) & 1) {
                    count++;
                }
            }
            // 更新最大組合大小
            ans = std::max(ans, count);
        }
        return ans;
    }
};
