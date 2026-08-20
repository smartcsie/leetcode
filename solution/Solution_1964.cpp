/**
 * 題目：1964. Find the Longest Valid Obstacle Course at Each Position
 * 難度：困難 (Hard)
 * 描述：給定一個障礙物高度陣列 obstacles，對每個位置 i，求「只用
 * obstacles[0..i] 這些障礙物、且必須以 obstacles[i] 結尾」能組成的
 * 最長非遞減子序列長度（允許相等高度）。
 *
 * 時間複雜度：O(N log N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （Patience Sorting，二分搜尋優化版 LIS，跟 354 同一招，只是這裡要求
 * 每個位置都要輸出答案，而不是只要最終答案）：
 * 1. n 最多到 10^5，標準 O(N²) 的 LIS DP（像 300/673/646 那樣兩層迴圈）
 *    會超時，所以要用維護 tails 陣列的二分搜尋版本，把單次查詢降到
 *    O(log N)。
 * 2. tails[k] 代表「目前長度為 k+1 的非遞減子序列，結尾可能的最小值」。
 * 3. 對每個 obstacles[i]，用 upper_bound 在 tails 裡找第一個「大於」
 *    obstacles[i] 的位置 idx（注意這題允許相等高度，所以是非遞減、
 *    要用 upper_bound，不是嚴格遞增的 lower_bound）：
 *    - idx 剛好等於 tails 目前長度：代表 obstacles[i] 可以接在最長的
 *      非遞減子序列後面，長度 +1，push_back 進 tails。
 *    - 否則：把 tails[idx] 換成 obstacles[i]（讓長度為 idx+1 的子序列
 *      結尾盡量小，之後才有更多機會接更多元素）。
 * 4. 關鍵點：不管是哪種情況，`idx + 1` 就是「以 obstacles[i] 結尾」的
 *    最長非遞減子序列長度——這正是題目要的答案，不用等到最後才回傳，
 *    每個位置處理完當下就能直接記錄 ans[i] = idx + 1。
 */
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> ans(n);
        vector<int> tails;
        for (int i = 0; i < n; ++i) {
            int x = obstacles[i];
            int idx = upper_bound(tails.begin(), tails.end(), x) - tails.begin();
            if (idx == (int)tails.size()) tails.push_back(x);
            else tails[idx] = x;
            ans[i] = idx + 1;
        }
        return ans;
    }
};
