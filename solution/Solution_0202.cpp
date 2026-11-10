/**
 * 題目：202. Happy Number
 * 難度：簡單 (Easy)
 * 描述：對一個數反覆執行「各位數字的平方和」運算，
 * 若最終結果為 1 則為快樂數，否則會陷入無限循環。
 *
 * 時間複雜度：O(logN)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （Floyd 快慢指針偵測循環）：
 * 不快樂數最終會進入循環，快樂數最終會到達 1。
 * 用快慢指針偵測是否有循環：
 * - slow 每次走一步
 * - fast 每次走兩步
 * - 若 fast == 1：是快樂數
 * - 若 fast == slow：進入循環，不是快樂數
 *
 * 與 unordered_set 版本的差異：
 * 不需要額外空間記錄已見過的數字，空間複雜度 O(1)。
 */
class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1;
    }
private:
    int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int d = n % 10;
            n /= 10;
            totalSum += d * d;
        }
        return totalSum;
    }
};