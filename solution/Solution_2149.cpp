/**
 * 題目：2149. Rearrange Array Elements by Sign (按符號重新排列陣列元素)
 * 難度：中等 (Medium)
 * 描述：將正數與負數交替排列，維持相對順序，且保證陣列元素數量相等且不為 0。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 */

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int pos = 0, neg = 1;
        vector<int> ans(n);
        int idx = 0;
        for(const int& x : nums) {
            if(x > 0) {
                ans[pos] = x;
                pos += 2;
            } else {
                ans[neg] = x;
                neg += 2;
            }
        }
        return ans;
    }
};
