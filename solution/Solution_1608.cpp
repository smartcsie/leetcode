/**
 * 題目：1608. Special Array With X Elements Greater Than or Equal X
 * 描述：給定一個非負整數陣列 nums。如果存在一個整數 x，
 *       使得陣列中剛好有 x 個元素大於或等於 x，則稱 nums 是一個「特殊陣列」。
 *       注意：x 不需要是 nums 中的元素。
 *       若存在這樣的 x，返回該 x；否則返回 -1。
 * 
 * 解法思路：
 * 1. x 的有效範圍必然在 0 到 nums.size() 之間（因為大於陣列長度的個數不可能成立）。
 * 2. 外層迴圈枚舉每一個可能的 x（從 1 開始到 nums.size()）。
 * 3. 內層迴圈遍歷整個 nums 陣列，統計有多少元素滿足 `v >= x`。
 * 4. 如果統計出的 count 剛好等於當前的 x，代表找到目標，直接返回 x。
 * 5. 若迴圈結束都沒找到，返回 -1。
 */

class Solution {
public:
    int specialArray(std::vector<int>& nums) {
        // x 的可能範圍從 1 到 nums.size()
        for (int x = 1; x <= nums.size(); ++x) {
            int count = 0;
            // 統計大於或等於 x 的元素個數
            for (int v : nums) {
                count += (v >= x);
            }
            // 如果剛好有 x 個元素大於或等於 x，則找到答案
            if (count == x) {
                return x;
            }
        }
        return -1;
    }
};
