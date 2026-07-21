/**
 * 題目：3314. Construct the Minimum Bitwise Array I
 * 描述：給定一個由正整數組成的陣列 nums。你需要構造一個長度相同的陣列 ans，
 *       其中 ans[i] 滿足 ans[i] | (ans[i] + 1) == nums[i]，
 *       且 ans[i] 必須是所有可能解中的「最小值」。若找不到則填入 -1。
 * 
 * 解法思路：
 * 1. 特殊邊界：數字 2 是唯一的例外，無法由任何 k | (k + 1) 產生，直接填入 -1。
 * 2. 位元運算優化：
 *    - 觀察 k | (k + 1) 的二進位特性，答案 k 其實是將 nums[i] 二進位中
 *      「最低位連續的 1」之中最高的那一顆 1 變成 0。
 *    - 具體實作：我們從右到左（從 bit 1 開始）檢查 nums[i]，
 *      找出第一個是 `0` 的位元位置 j。
 *    - 找到後，利用 XOR 遮罩 `1 << (j - 1)` 將對應的位元歸零，即可瞬間算出最小的 k。
 */

class Solution {
public:
    std::vector<int> minBitwiseArray(std::vector<int>& nums) {
        std::vector<int> op;
        for (int i = 0; i < nums.size(); i++) {
            // 數字 2 是特例，無解
            if (nums[i] == 2) {
                op.push_back(-1);
            } 
            else {
                // 從右到左尋找第一個為 0 的 bit 位置
                for (int j = 1; j < 32; j++) {
                    // 若當前位元是 0
                    if (((nums[i] >> j) & 1) == 0) {
                        // 利用 XOR 拔掉該連續 1 區段最左邊的那一個 1
                        op.push_back(nums[i] ^ (1 << (j - 1)));
                        break;
                    }
                }
            }
        }
        
        return op;
    }
};
