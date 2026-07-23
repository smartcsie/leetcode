/**
 * 題目：2600. K Items With the Maximum Sum
 * 描述：袋子中有 numOnes 個 1、numZeros 個 0、numNegOnes 個 -1。
 *       從中選出恰好 k 個物品，使得所選物品的總和最大。請返回最大的總和。
 * 
 * 解法思路：
 * 1. 貪婪策略：若要總和最大，我們應該優先拿完所有的 1，不夠再拿 0，最後才拿 -1。
 * 2. 判斷 k 的數量落在哪個區間：
 *    - 若 k 小於等於 (numOnes + numZeros)：代表 k 個名額只需要分配給 1 和 0 就能滿足。
 *      此時的最大總和就是「能拿多少個 1」，即 `min(numOnes, k)`（因為 0 對總和沒有貢獻）。
 *    - 若 k 超過了 (numOnes + numZeros)：代表 1 和 0 已經全拿完了，剩下的名額被迫必須拿 -1。
 *      此時總和為 `numOnes`（1 的總和）減去超出的負數個數 `(k - (numOnes + numZeros))`。
 */

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        // 三元運算子判斷 k 是否落在 1 與 0 的涵蓋範圍內
        return k <= (numOnes + numZeros) 
            ? std::min(numOnes, k) 
            : (numOnes - (k - (numOnes + numZeros)));
    }   
};
