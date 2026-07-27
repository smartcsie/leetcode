/**
 * 題目：1200. Minimum Absolute Difference (最小絕對差)
 * 難度：簡單 (Easy)
 * 描述：在陣列中找出所有絕對差值最小的相鄰元素數對。
 * * 時間複雜度：O(NlogN) - 主要開銷在於排序。
 * 空間複雜度：O(N) - 儲存結果數對。
 * * 優化思路：
 * 1. 預掃描：先掃描一次求出 minDiff，第二次掃描收集結果，避免 res.clear() 的開銷。
 * 2. 效能優化：使用 reserve 避免 vector 動態擴容。
 */

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = static_cast<int>(arr.size());
        int minDiff = INT_MAX;
        vector<vector<int>> res;
        for(int i = 0; i < n - 1; i++) {
            minDiff = min(minDiff, arr[i + 1] - arr[i]);
        }
        for(int i = 0; i < n - 1; i++) {
            if((arr[i + 1] - arr[i]) == minDiff) {
                res.push_back({arr[i], arr[i + 1]});
            }
        }
        return res;
    }
};
