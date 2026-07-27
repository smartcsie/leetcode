/**
 * 題目：2148. Count Elements With Strictly Smaller and Greater Elements
 * 難度：簡單 (Easy)
 * 描述：計算陣列中嚴格小於最大值且嚴格大於最小值的元素個數。
 * * 時間複雜度：O(N) - 僅進行一次極值查找與一次頻率統計。
 * 空間複雜度：O(1) - 不依賴額外的容器。
 * * 優化思路：
 * 1. 邏輯簡化：透過總長度扣除極值個數，避免複雜的判斷式。
 * 2. 防禦性：若最大值與最小值相同（所有元素相等），應回傳 0。
 */

class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        auto [minIt, maxIt] = minmax_element(nums.begin(), nums.end());
        int min = *minIt;
        int max = *maxIt;
        int count = 0;
        for(const int& num : nums) {
            if(num == max || num == min) count++;
        }
        return n - count;
    }
};
