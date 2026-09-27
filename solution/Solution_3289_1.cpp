/*
 * 題目：3289. The Two Sneaky Numbers of Digitville
 * 連結：https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/
 * 難度：Easy
 * 分類主題：Array, Hash Table
 * 技巧：暴力雙層迴圈找重複值
 * 描述：nums 長度為 n+2，內容原本應該是 0 ~ n-1 各出現一次，
 *       但其中有兩個數字各自多出現了一次（重複），找出這兩個數字（順序不拘）。
 * 時間複雜度：O(N^2)，雙層迴圈枚舉所有 (i, j) 配對
 * 空間複雜度：O(1)，不計輸出用的 ans（最多只存 2 個元素）
 * 解法思路：
 *   1. 雙層迴圈暴力比較每一對 (i, j)，i < j。
 *   2. 若 nums[i] == nums[j]，代表這個值就是重複出現的「偷跑數字」，
 *      將其加入 ans。
 *   3. 因為題目保證恰好有兩個數字各重複一次，所以整個雙層迴圈跑完，
 *      ans 一定會剛好蒐集到兩個值。
 *   注意：這是 O(N^2) 暴力解，若想優化到 O(N)，
 *         可以改用 vector<int> count(n, 0) 或 bitset 計數，
 *         走訪一次 nums，遇到 count[x]++ 到 2 就把 x 放進答案。
 */
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        // 枚舉所有 i < j 的配對，找出值相同的重複數字
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) ans.push_back(nums[j]);
            }
        }
        return ans;
    }
};