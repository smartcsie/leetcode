/**
 * 題目：278. First Bad Version (第一個錯誤的版本)
 * 難度：簡單 (Easy)
 * 描述：在 1 到 n 的版本中，透過 API 找出第一個導致系統錯誤的版本。
 * * 時間複雜度：O(log N) - 二分搜尋法，每次縮小一半範圍。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 設計思路：
 * 這是「尋找左邊界」的二分搜尋。
 * 若 mid 為錯誤版本，則第一個錯誤版本可能就是 mid 或在 mid 左邊，故 right = mid。
 * 若 mid 為正常版本，則第一個錯誤版本必然在 mid 右邊，故 left = mid + 1。
 */

// The API is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        
        // 使用 l < r，當循環結束時，left 將等於 right
        while (left < right) {
            // 使用此公式避免 (left + right) 超出 int 範圍的溢位問題
            int mid = left + (right - left) / 2;
            
            if (isBadVersion(mid)) {
                // mid 可能是第一個錯誤版本，保留 mid
                right = mid;
            } else {
                // mid 是正常版本，第一個錯誤版本在右側，故從 mid + 1 開始
                left = mid + 1;
            }
        }
        
        // 迴圈結束時 left == right，即為第一個錯誤版本
        return left;
    }
};
