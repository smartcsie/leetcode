/**
 * 題目：1299. Replace Elements with Greatest Element on Right Side (將每個元素替換為右側最大元素)
 * 難度：簡單 (Easy)
 * 描述：將陣列中每個元素替換為其右側所有元素中的最大值，最後一個元素替換為 -1。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n =  arr.size();
        int mx = -1;
        vector<int> ans(n);
        for(int i = n - 1; i >= 0; i--) {
            ans[i] = mx;
            mx = max(mx, arr[i]);
        }
        return ans;
    }
};
