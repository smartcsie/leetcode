/**
 * 題目：852. Peak Index in a Mountain Array (山脈陣列的峰頂索引)
 * 難度：中等 (Medium)
 * 描述：在滿足山脈特性（先嚴格遞增後嚴格遞減）的陣列中，找出峰頂元素的索引。
 *
 * 時間複雜度：O(logN)
 * 空間複雜度：O(1)
 *
 * 設計思路：
 * 1. 比較中間元素與其下一個元素： 1. 若 arr[m] < arr[m+1]，代表峰頂必然在 m 的右側（包含 m+1）。
 * 2. 2. 若 arr[m] > arr[m+1]，代表 m 可能是峰頂，或者峰頂在 m 的左側。
 */

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] < arr[mid + 1]) left = mid + 1;
            else right = mid; 
        }
        return left;
    }
};
