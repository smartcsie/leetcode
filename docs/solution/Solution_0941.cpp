/**
 * 題目：941. Valid Mountain Array (有效的山脈陣列)
 * 難度：簡單 (Easy)
 * 描述：檢查陣列是否為山脈陣列（先遞增後遞減，且長度至少為 3）。
 * 
 * 時間複雜度：O(n) - 兩個指標最多遍歷陣列各一次。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * 
 * 解法思路：
 * 1. 山脈特性：存在一個頂峰 i，滿足 0 < i < n-1。
 * 2. 左指標 `left` 從左向右攀爬，直到無法繼續遞增。
 * 3. 右指標 `right` 從右向左攀爬，直到無法繼續遞減。
 * 4. 若這兩個指標最終停在同一個位置，且該位置不是起點也不是終點，則為有效山脈。
 */

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        auto n = arr.size();
        if(n <= 2) return false;
        int left = 0;
        int right = n-1;
        while(left < n-1 && arr[left] < arr[left+1]) left++;
        while(right > 0 && arr[right] < arr[right-1]) right--;
        if(left == 0 || right == n-1) return false;
        return left == right;
    }
};
