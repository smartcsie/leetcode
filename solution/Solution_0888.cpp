/**
 * 題目：888. Fair Candy Swap
 * 難度：簡單 (Easy)
 * 描述：找出兩組糖果中各一個交換，使雙方總量相等。
 *
 * 時間複雜度：O(A+B) - 需計算總和並將 Bob 的糖果放入 Set。
 * 空間複雜度：O(B) - 用於儲存 Bob 的糖果集合。
 *
 * 解法思路：
 * 1. 設 Alice 的糖果交換出 x，收到 y；Bob 的糖果交換出 y，收到 x。
 * 2. 交換後總和相等：SumA - x + y = SumB - y + x
 * 3. 整理得：y - x = (SumB - SumA) / 2。
 * 4. 設 diff = (SumB - SumA) / 2，則 y = x + diff。
 * 5. 遍歷 Alice 的糖果 x，檢查 Bob 是否有 y = x + diff。
 */

class Solution {
public:
    std::vector<int> fairCandySwap(std::vector<int>& aliceSizes, std::vector<int>& bobSizes) {
        vector<int>& aVec = aliceSizes;
        vector<int>& bVec = bobSizes;
        int sumA = 0, sumB = 0;
        for(const int& x : aVec) sumA += x;
        for(const int& x : bVec) sumB += x;
        int diff = (sumB - sumA) / 2;
        unordered_set bSet(bVec.begin(), bVec.end());
        for(const int& x : aVec) {
            if(bSet.count(x + diff)) return {x, x+ diff};
        }
        return {};
    }
};
