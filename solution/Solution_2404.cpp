
/**
 * 題目：2404. Most Frequent Even Element (出現次數最多的偶數元素)
 * 難度：簡單 (Easy)
 * 描述：給你一個整數陣列 nums，回傳出現次數最多的偶數元素。
 * 如果有兩個以上的偶數元素出現次數相同，則回傳其中「最小」的一個。
 * 如果不存在偶數元素，則回傳 -1。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 1. 使用 unordered_map<int, int> 紀錄每個「偶數」出現的頻率。
 * 2. 同時維護兩個變數：
 * - maxFreq: 當前紀錄到的最高頻率。
 * - ans: 目前最高頻率對應的最小偶數（初始化為 -1）。
 * 3. 遍歷 map，如果遇到頻率更高，或頻率相同但數值更小的偶數，則更新 ans。
 */


class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> counts;
        int mx = 0;
        int ans = INT_MAX;
        for(const int& num : nums) {
            if((num & 1) == 0) {
                counts[num]++;
                if(counts[num] > mx) {
                    mx = counts[num];
                    ans = num;
                } else if(counts[num] == mx) {
                    ans = min(num, ans);
                }
                
            }
        }
        return counts.empty() ? -1 : ans;
    }
};
