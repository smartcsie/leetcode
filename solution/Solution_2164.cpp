/**
 * 題目：2164. Sort Even and Odd Indices Independently
 * 難度：簡單 (Easy)
 * 描述：偶數索引非遞減，奇數索引非遞增。
 *
 * 時間複雜度：O(NlogN)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 1. 使用 reserve() 預分配記憶體，避免動態擴充開銷。
 * 2. 使用標準的迭代器操作進行回填，確保安全性。
 */

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> oddeven(2);
        for(int i = 0; i < n; i++) {
            oddeven[i & 1].push_back(nums[i]);
        }
        sort(oddeven[0].begin(), oddeven[0].end());
        sort(oddeven[1].begin(), oddeven[1].end(), greater<>());
        for(int i = 0; i < n; i++) {
            nums[i] = oddeven[i & 1][i >> 1];
        }
        return nums;
    }
};
