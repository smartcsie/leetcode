/**
 * 題目：1920. Build Array from Permutation
 * 難度：簡單 (Easy)
 * 描述：根據規則 nums[i] = nums[nums[i]] 構建新陣列。
 * * 優化重點：
 * 1. 空間極致優化：達到 O(1) 空間複雜度（不計算回傳陣列）。
 * 2. 編碼技巧：利用 (a + (b % n) * n) 的數學性質，在一個整數中存入舊值與新值。
 */

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i< n; i++) {
            nums[i] = nums[i] + n * (nums[nums[i]] % n);
        }
        for(int i = 0 ; i< n; i++) {
            nums[i] /= n;
        }
        return nums;
    }
};
