/**
 * 題目：1200. Minimum Absolute Difference (最小絕對差)
 * 難度：簡單 (Easy)
 * 描述：在陣列中找出所有絕對差值最小的相鄰元素數對。
 *
 * 時間複雜度：O(NlogN)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 1. 預掃描：先掃描一次求出 minDiff，第二次掃描收集結果，避免 res.clear() 的開銷。
 * 2. 效能優化：使用 reserve 避免 vector 動態擴容。
 */

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int mn = 1e8;
        vector<vector<int>> ans;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] - arr[i - 1] < mn) {
                mn = arr[i] - arr[i - 1];
                ans = {{arr[i - 1], arr[i]}};
            } else if(arr[i] - arr[i - 1] == mn) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }
        return ans;
    }
};
