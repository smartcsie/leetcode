/**
 * 題目：374. Guess Number Higher or Lower (猜數字遊戲)
 * 難度：簡單 (Easy)
 * 描述：在 1 到 n 之間猜數字，利用 guess(num) API 判斷猜測值與答案的大小關係。
 * * 時間複雜度：O(log N) - 每次猜測都將範圍縮小一半。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 設計思路：
 * 這是經典的二分搜尋。API 的定義如下：
 * -1: 猜的值太高 (pick < num)
 * 1: 猜的值太低 (pick > num)
 * 0: 猜對了 (pick == num)
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        
        while (left <= right) {
            // 使用 left + (right - left) / 2 防止整數溢位 (Integer Overflow)
            int mid = left + (right - left) / 2;
            int res = guess(mid);
            
            if (res == 0) {
                return mid; // 猜對了
            } else if (res == -1) {
                right = mid - 1; // 數字太大，往左半區找
            } else {
                left = mid + 1; // 數字太小，往右半區找
            }
        }
        
        return -1; // 根據題意應必有解，但在這裡回傳 -1 作為防禦性編程
    }
};
