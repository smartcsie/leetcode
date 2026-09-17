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
        vector<int>& as = aliceSizes;
        vector<int>& bs = bobSizes;
        int asum = accumulate(as.begin(), as.end(), 0);
        int bsum = accumulate(bs.begin(), bs.end(), 0);
        int target = (asum - bsum) / 2;
        unordered_set<int> aset(as.begin(), as.end());
        for(const int& y : bs) {
            int x = target + y;
            if(aset.contains(x)) return {x, y};
        }
        return {-1, -1};
    }
};
