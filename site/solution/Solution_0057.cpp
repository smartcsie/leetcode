/**
 * 題目：57. Insert Interval (插入區間)
 * 難度：中等 (Medium)
 * 描述：在一個已排序且無重疊的區間列表中插入新區間，並合併所有重疊的區間。
 * * 時間複雜度：O(N) - 遍歷一次區間列表。
 * 空間複雜度：O(N) - 建立一個新的結果陣列。
 * * 優化思路：
 * 將處理過程分為三個清晰的階段：
 * 1. `while`: 將所有完全在 newInterval 左側的區間加入結果。
 * 2. `while`: 合併所有與 newInterval 有交集的區間（更新邊界）。
 * 3. `while`: 將所有剩餘的區間加入結果。
 */

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        int n = intervals.size();

        // 1. 加入所有 newInterval 左側且不重疊的區間
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i++]);
        }

        // 2. 合併所有重疊的區間
        // 當 intervals[i] 的開始點 <= newInterval 的結束點，代表有重疊
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval); // 加入合併後的區間

        // 3. 加入剩餘右側不重疊的區間
        while (i < n) {
            res.push_back(intervals[i++]);
        }

        return res;
    }
};
