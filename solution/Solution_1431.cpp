/**
 * 題目：1431. Kids With the Greatest Number of Candies (擁有最多糖果的孩子)
 * 難度：簡單 (Easy)
 * 描述：判斷每個小孩加上額外糖果後，是否為擁有最多糖果的人。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 設計思路：
 * 1. 將題目要求的 `candies[i] + extraCandies >= max` 改寫為 `candies[i] >= max - extraCandies`。
 * 2. 這樣只需要做一次減法，減少了迴圈內每次都要做加法的開銷。
 */

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = *max_element(candies.begin(), candies.end());
        int n = candies.size();
        vector<bool> ans(n);
        int mn = mx - extraCandies;
        for(int i = 0;i < n ; i++) {
            if(candies[i] >= mn) ans[i] = true;
        }
        return ans;
    }
};
