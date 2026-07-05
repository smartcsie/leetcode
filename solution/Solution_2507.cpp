/**
 * 題目：2507. Smallest Value After Replacing With Sum of Prime Factors
 * 難度：中等 (Medium)
 * 描述：重複將數字替換為其質因數之和，直到數字不再改變。
 * * 優化重點：
 * 1. 分解優化：質因數分解只需遍歷到 sqrt(n)，大幅提升效能。
 * 2. 邊界檢查：若 n 為質數，質因數分解會直接回傳 n 本身，迴圈條件即自動終止。
 */

class Solution {
private:
    int getPrimeSum(int n) {
        int primeSum = 0;
        int d = n;
        // 只需遍歷到 sqrt(d)
        for (int i = 2; i * i <= d; i++) {
            while (d % i == 0) {
                primeSum += i;
                d /= i;
            }
        }
        // 若 d > 1，表示剩餘部分為一個大質數
        if (d > 1) primeSum += d;
        return primeSum;
    }

public:
    int smallestValue(int n) {
        while (true) {
            int sum = getPrimeSum(n);
            // 若總和等於原數，表示已收斂
            if (sum == n) return n;
            n = sum;
        }
    }
};
