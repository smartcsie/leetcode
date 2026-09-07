/**
 * 題目：1122. Relative Sort Array (陣列的相對排序)
 * 難度：簡單 (Easy)
 * 描述：根據 arr2 的順序排列 arr1，未出現的元素按遞增排序接在後面。
 *
 * 時間複雜度：O(N+K)
 * 空間複雜度：O(K)
 *
 * 解法思路：
 * 1. 頻率統計：使用定長陣列 counts[1001] 記錄每個數字出現次數。
 * 2. 順序填入：先遍歷 arr2 填入特定順序，再線性掃描 counts 陣列填入剩餘數字。
 */

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> counts(1001, 0);
        for(const int& x : arr1) counts[x]++;
        vector<int> ans(arr1.size());
        int idx = 0;
        for(const int& x : arr2) {
            while(counts[x]-- > 0) ans[idx++] = x;
        }
        for( int i = 0; i <= 1000; i++) {
            while(counts[i]-- > 0 ) ans[idx++] = i;
        }
        return ans;
    }
};