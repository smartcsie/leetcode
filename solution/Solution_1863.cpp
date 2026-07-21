/**
 * 題目：1863. Sum of All Subset XOR Totals
 * 描述：給定一個整數陣列 nums，找出 nums 所有子集 (Subsets) 的 XOR 總和，
 *       並返回這些 XOR 總和的加總。
 * 
 * 解法思路：
 * 1. 數學推導性質：
 *    - 如果某個位元（Bit）在整個陣列的二進位中至少出現過一次 1，
 *      那麼在所有 $2^N$ 個子集中，剛好有一半的子集會讓這個位元的總和為 1（即 $2^{N-1}$ 個子集）。
 *    - 因此，所有子集 XOR 總和的總和，等於「全體元素的 Bitwise OR 總和」乘以 $2^{N-1}$。
 * 2. 實作細節：
 *    - 使用 std::reduce 搭配 std::bit_or 計算整個陣列的 OR 總和。
 *    - 利用左移運算子 << (nums.size() - 1) 來達到乘以 $2^{N-1}$ 的效果。
 */

class Solution {
public:
    int subsetXORSum(std::vector<int>& nums) {
        // 1. reduce(..., bit_or<int>())：計算整個 nums 陣列所有元素的位元 OR 聯集
        // 2. << (nums.size() - 1)：將 OR 結果向左位移 N-1 位（等同於乘以 2^(N-1)）
        return std::reduce(nums.begin(), nums.end(), 0, std::bit_or<int>()) << (nums.size() - 1);
    }
};
