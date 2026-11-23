/**
 * 題目：888. Fair Candy Swap
 * 難度：簡單 (Easy)
 * 描述：找出兩組糖果中各一個交換，使雙方總量相等。
 *
 * 時間複雜度：O(A+B)
 * 空間複雜度：O(B)
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
        int aSum = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int bSum = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int diff = (bSum - aSum) / 2;
        unordered_set<int> bSet(bobSizes.begin(), bobSizes.end());
        for(const int& x : aliceSizes) {
            if(bSet.contains(x + diff)) return {x, x + diff};
        }
        return {-1, -1};
    }
};
