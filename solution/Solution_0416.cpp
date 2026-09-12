/**
 * 題目：416. Partition Equal Subset Sum (分割等和子集)
 * 難度：中等 (Medium)
 * 描述：判斷陣列是否可分割為兩個和相等的子集。
 *
 * 時間複雜度：O(N*S/W)
 * 空間複雜度：O(S/W)
 *
 * 解法思路：
 * 1. 剪枝：若總和為奇數，直接回傳 false。
 * 2. Bitset DP：將每個數字視為位元位移運算，bits |= (bits << num) 表示「若原本能組成某和，加上 num 後亦能組成該和」。
 */

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<10001> bits(1);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for(const int& num : nums) {
            bits |= bits << num;
        }
        return (sum % 2 == 0) && bits[sum >> 1];
    }
};
