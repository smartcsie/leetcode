/**
 * 題目：852. Peak Index in a Mountain Array (山脈陣列的峰頂索引)
 * 難度：中等 (Medium)
 * 描述：在滿足山脈特性（先嚴格遞增後嚴格遞減）的陣列中，找出峰頂元素的索引。
 * * 時間複雜度：O(log N) - 典型的二分搜尋，每次迭代排除一半的範圍。
 * 空間複雜度：O(1) - 僅使用常數空間變數。
 * * 設計思路：
 * 比較中間元素與其下一個元素：
 * 1. 若 arr[m] < arr[m+1]，代表峰頂必然在 m 的右側（包含 m+1）。
 * 2. 若 arr[m] > arr[m+1]，代表 m 可能是峰頂，或者峰頂在 m 的左側。
 */

#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        
        // 使用 l < r 的循環，當 l 與 r 重合時即為峰頂
        while (left < right) {
            int mid = l + (right - left) / 2;
            
            // 如果當前處於遞增坡道，則峰頂在右側
            if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            } 
            // 如果當前處於遞減坡道或位於頂部，則峰頂在左側（包含當前 m）
            else {
                right = mid;
            }
        }
        
        return right; // 或回傳 l，因為 l == r
    }
};
