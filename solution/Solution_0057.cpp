/**
 * 題目：57. Insert Interval (插入區間)
 * 難度：中等 (Medium)
 * 描述：在一個已排序且無重疊的區間列表中插入新區間，並合併所有重疊的區間。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 將處理過程分為三個清晰的階段：
 * 1. `while`: 將所有完全在 newInterval 左側的區間加入結果。
 * 2. `while`: 合併所有與 newInterval 有交集的區間（更新邊界）。
 * 3. `while`: 將所有剩餘的區間加入結果。
 */

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>& itvs = intervals;
        vector<int>& newItv = newInterval;
        vector<vector<int>> ans;
        int idx = 0;
        int n = itvs.size();
        while(idx < n && itvs[idx][0] < newItv[0]) ans.push_back(itvs[idx++]);

        if(ans.empty() || (ans.back()[1] < newItv[0])) ans.push_back(newItv);
        else ans.back()[1] = max(ans.back()[1], newItv[1]);

        while(idx < n) {
            if(ans.back()[1] < itvs[idx][0]) ans.push_back(itvs[idx]);
            else ans.back()[1] = max(ans.back()[1], itvs[idx][1]);
            idx++;
        }
        return ans;
    }
};