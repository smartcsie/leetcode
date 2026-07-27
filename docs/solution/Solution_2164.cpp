/**
 * 題目：2164. Sort Even and Odd Indices Independently
 * 難度：簡單 (Easy)
 * 描述：偶數索引非遞減，奇數索引非遞增。
 * * 時間複雜度：O(N log N) - 排序佔主要開銷。
 * 空間複雜度：O(N) - 額外儲存分離後的陣列。
 * * 優化思路：
 * 1. 使用 reserve() 預分配記憶體，避免動態擴充開銷。
 * 2. 使用標準的迭代器操作進行回填，確保安全性。
 */

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return nums;
        vector<int> even, odd;
        for(int i = 0; i < n; i ++) {
            if(i % 2 == 0)  even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }
        sort(odd.begin(), odd.end(), greater<>());
        sort(even.begin(), even.end());
        auto eIt = even.begin();
        auto oIt = odd.begin();
        for(int i = 0; i < n; i ++) {
            if(i % 2 == 0) nums[i] = *eIt++;
            else  nums[i] = *oIt++;
        }
        return nums;
    }
};
