/**
 * 題目：1780. Check if Number is a Sum of Powers of Three
 * 難度：中等 (Medium)
 * 描述：判斷一個整數 n 是否能表示為若干個「不重複」的 3 的冪次之和。
 * * 優化重點：
 * 1. 數學本質：任何數字皆可唯一表示為 3 進位。若 n 能表示為相異 3 的冪次方之和，
 * 則其 3 進位表示中每一位只能為 0 或 1。
 * 2. 演算法：不斷對 n 取 3 的餘數，若發現餘數為 2，代表該位數包含了 2 個 3^k，
 * 違反了「不重複」的條件，直接返回 false。
 */

class Solution {
public:
    bool checkPowersOfThree(int n) {
        // 不斷將 n 除以 3，檢測每一位數是否包含 2
        while (n > 0) {
            // 若餘數為 2，表示該位數使用了 2 個 3^k，不符合條件
            if (n % 3 == 2) {
                return false;
            }
            n /= 3;
        }
        return true;
    }
};
