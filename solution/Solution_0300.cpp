/**
 * 題目：300. Longest Increasing Subsequence (最長遞增子序列)
 * 難度：中等 (Medium)
 * 描述：給你一個整數陣列 nums，找到其中最長嚴格遞增子序列的長度。
 * 
 * 時間複雜度：O(n log n) - 遍歷陣列一次 O(n)，每次處理使用二分搜尋 O(log n)。
 * 空間複雜度：O(n) - 最壞情況下需要儲存與原陣列等長的序列。
 * 
 * 解法：耐心排序 (Patience Sorting) / 二分搜尋優化
 * 維護一個 tails 陣列，tails[i] 代表長度為 i+1 的遞增子序列中，結尾最小的數字。
 * 透過不斷更新這個陣列，我們可以確保子序列增長得最慢，從而留下更多空間給後面的數字。
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for (int x : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) {
                tails.push_back(x);
            } else {
                *it = x;
            }
        }
        return tails.size();
    }
};
