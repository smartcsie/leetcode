/**
 * 題目：3819. Rotate Non Negative Elements
 * 難度：簡單 (Easy)
 * 描述：將陣列中所有非負數向左旋轉 k 位，負數保持原位。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 1. 使用 reserve() 減少動態記憶體分配次數。
 * 2. 透過 range-based for loop 與 reference 寫回原陣列，提升可讀性。
 */

class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> nonNeg;
        for(const int& x : nums) {
            if(x >= 0) nonNeg.push_back(x);
        }
        int n = nonNeg.size();
        if(n == 0) return nums;
        k %= n;
        rotate(nonNeg.begin(), nonNeg.begin() + k, nonNeg.end());
        int idx = 0;
        for(int& x : nums) {
            if(x >= 0) x = nonNeg[idx++];
        }
        return nums;
    }
};