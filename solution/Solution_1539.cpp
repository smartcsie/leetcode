/**
 * 題目：1539. Kth Missing Positive Number (第 k 個缺失的正整數)
 * 難度：簡單 (Easy)
 * 描述：在已排序的陣列中，找出第 k 個缺失的正整數。
 * * 時間複雜度：O(log N) - 二分搜尋法。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 1. 對於陣列中的每個元素 arr[mid]，該位置之前缺失的數字個數為：arr[mid] - (mid + 1)。
 * 2. 若缺失數字小於 k，說明目標在右側 (left = mid + 1)；反之在左側 (right = mid - 1)。
 * 3. 搜尋結束後，結果為 left + k。
 */

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0;
        int right = arr.size() - 1;
        
        // 使用二分搜尋找出第一個「缺失數字個數大於等於 k」的索引位置
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // arr[mid] - (mid + 1) 代表 arr[mid] 之前總共缺失了多少個數字
            if (arr[mid] - (mid + 1) < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        // 最終 left 為第一個缺失數大於等於 k 的位置，
        // 而答案即為 left + k
        return left + k;
    }
};
