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
 * （硬編碼不快樂循環成員）：
 * 數學事實：所有不快樂數最終都會進入固定循環
 * {4, 16, 37, 58, 89, 145, 42, 20}。
 * 只要遇到這些數字之一，就確定不是快樂數。
 *
 * 與其他解法的比較：
 * - unordered_set 動態記錄版：O(logN) 空間
 * - Floyd 快慢指針版：O(1) 空間但需要兩個指針
 * - 此解法：O(1) 空間，邏輯最簡單，利用數學性質直接判斷
 */
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> cycle_members = {4, 16, 37, 58, 89, 145, 42, 20};
        while (n != 1 && cycle_members.find(n) == cycle_members.end()) {
            n = getNext(n);
        }
        return n == 1;
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