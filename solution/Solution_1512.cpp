/**
 * 題目：1512. Number of Good Pairs (好數對的數目)
 * 難度：簡單 (Easy)
 * 描述：計算所有滿足 nums[i] == nums[j] 且 i < j 的數對 (i, j)。
 * * 時間複雜度：O(N) - 僅遍歷一次陣列。
 * 空間複雜度：O(N) - 使用雜湊表儲存頻率。
 * * 優化思路：
 * 利用數學規律：若某數字已出現 k 次，新加入的一個相同數字可與先前 k 個組成 k 個新組合。
 */

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> counts;
        int res = 0;
        for(int num : nums) {
            res += counts[num];
            counts[num]++;
        }
        return res;
    }
};
