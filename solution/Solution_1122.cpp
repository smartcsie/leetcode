/**
 * 題目：1122. Relative Sort Array (陣列的相對排序)
 * 難度：簡單 (Easy)
 * 描述：根據 arr2 的順序排列 arr1，未出現的元素按遞增排序接在後面。
 * * 時間複雜度：O(N + K)，N 為 arr1 長度，K 為數值範圍 (1001)。
 * 空間複雜度：O(K) - 固定大小的計數陣列。
 * * 優化思路：
 * 1. 頻率統計：使用定長陣列 counts[1001] 記錄每個數字出現次數。
 * 2. 順序填入：先遍歷 arr2 填入特定順序，再線性掃描 counts 陣列填入剩餘數字。
 */

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // 使用定長陣列進行頻率計數 (假設元素範圍 0-1000)
        int counts[1001] = {0};
        for (const int num : arr1) {
            counts[num]++;
        }
        
        vector<int> res;
        res.reserve(arr1.size()); // 預先分配記憶體以減少動態擴容開銷

        // 1. 按照 arr2 的順序填入
        for (const int num : arr2) {
            while (counts[num] > 0) {
                res.push_back(num);
                counts[num]--;
            }
        }

        // 2. 剩餘元素直接掃描計數陣列
        // 由於 i 是遞增的，剩餘元素會自動按遞增順序填入
        for (int i = 0; i <= 1000; ++i) {
            while (counts[i] > 0) {
                res.push_back(i);
                counts[i]--;
            }
        }

        return res;
    }
};
