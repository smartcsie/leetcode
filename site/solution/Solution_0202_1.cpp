/**
 * 題目：202. Happy Number (快樂數)
 * 難度：簡單 (Easy)
 * 描述：判斷一個數字 n 是不是快樂數。
 * 快樂數定義：對於一個正整數，每一次將該數替換為它每個位置上的數字的平方和。
 * 重複這個過程，如果最終數字變為 1，則是快樂數；如果過程陷入循環且不包含 1，則不是。
 * * 時間複雜度：O(log n) - 數字縮小的速度非常快。
 * 空間複雜度：O(1) - 使用快慢指標，不需要額外的資料結構儲存歷史紀錄。
 */

#include <iostream>

class Solution {
public:
    /**
     * 輔助函數：計算數字各個位數的平方和
     */
    int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int d = n % 10;    // 取出個位數
            n = n / 10;        // 去掉個位數
            totalSum += d * d; // 累加平方
        }
        return totalSum;
    }

    bool isHappy(int n) {
        // 使用快慢指標 (龜兔賽跑演算法) 來偵測循環
        // slow 每次走一步，fast 每次走兩步
        int slow = n;
        int fast = getNext(n);

        // 如果 fast 變成了 1，或是 fast 與 slow 相遇（代表進入循環），則停止
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);           // 走一步
            fast = getNext(getNext(fast));  // 走兩步
        }

        // 如果最後是因為 fast 變成 1 而跳出循環，則代表是快樂數
        return fast == 1;
    }
};

/**
 * 解法思路：
 * 1. 快樂數的變化過程最終只有兩種結果：變為 1，或者陷入死循環。
 * 2. 這可以類比為鏈表（LinkedList）中是否有環的問題。
 * 3. 快慢指標法：
 * - 如果沒有環（最終變為 1），快指標一定會先到達 1。
 * - 如果有環，快指標最終會在環內追上慢指標（兩者相等且不為 1）。
 */
