/**
 * 題目：441. Arranging Coins
 * 難度：簡單 (Easy)
 * 描述：給定 n 枚硬幣，按照樓梯形狀排列（第 k 行放 k 枚），
 * 求能完整排滿的最多行數。
 *
 * 時間複雜度：O(logN)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （Binary Search Find Right Bound）：
 * 排滿 k 行需要 k*(k+1)/2 枚硬幣，對 k 做二分搜尋。
 * 1. 找最大的 k 使得 k*(k+1)/2 <= n。
 * 2. coins == n：恰好排滿，直接回傳 mid。
 * 3. coins > n：k 太大，right = mid - 1。
 * 4. coins < n：k 太小，left = mid + 1。
 * 5. 迴圈結束時 right 就是答案（最後一個滿足 coins <= n 的 k）。
 *
 * 注意：mid * (mid + 1) 可能超過 int 範圍，需用 long 計算。
 */
class Solution {
public:
    int arrangeCoins(int n) {
        long left = 0, right = n;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            long coins = mid * (mid + 1) / 2;
            if (coins == n) return static_cast<int>(mid);
            if (coins > n) right = mid - 1;
            else           left  = mid + 1;
        }
        return static_cast<int>(right);  // 最後一個 coins <= n 的 k
    }
};