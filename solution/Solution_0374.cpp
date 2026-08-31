/**
 * 題目：374. Guess Number Higher or Lower (猜數字遊戲)
 * 難度：簡單 (Easy)
 * 描述：在 1 到 n 之間猜數字，利用 guess(num) API 判斷猜測值與答案的大小關係。
 *
 * 時間複雜度：O(logN)
 * 空間複雜度：O(1)
 *
 * 設計思路：
 * 1. 這是經典的二分搜尋。
 * 2. API 的定義如下： -1: 猜的值太高 (pick < num) 1: 猜的值太低 (pick > num) 0: 猜對了 (pick == num)。
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(guess(mid) == 0) return mid;
            else if(guess(mid) == -1) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
};
