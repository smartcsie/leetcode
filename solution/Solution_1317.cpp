/**
 * 題目：1317. Convert Integer to the Sum of Two No-Zero Integers
 * 描述：給定一個整數 n，將其表示為兩個「不包含數字 0 的正整數」之和。
 *       若有多個可能解，返回其中任意一個即可。題目保證一定存在至少一個解。
 * 
 * 解法思路：
 * 1. 輔助函式 hasZero(int n)：透過取餘數與除以 10 (n % 10, n / 10)，
 *    檢查一個數字的十進位表示中是否包含數字 0。
 * 2. 主邏輯 getNoZeroIntegers(int n)：
 *    - 從 i = 1 開始迴圈遞增到 n - 1。
 *    - 每次檢查 i 與 n - i 是否都不包含 0（即 !hasZero(i) && !hasZero(n - i)）。
 *    - 若雙雙符合條件，立即回傳 {i, n - i}。
 */

class Solution {
private:
    bool hasZero(int n) {
        while (n > 0) {
            if (n % 10 == 0) return true; // 發現個位數為 0
            n /= 10;
        }
        return false;
    }
public:
    std::vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            // 如果 i 和 n - i 兩者都不包含 0，這就是我們要找的答案
            if (!hasZero(i) && !hasZero(n - i)) {
                return {i, n - i};
            }
        }
        return {};
    }
};
