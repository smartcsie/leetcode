/**
 * 題目：435. Non-overlapping Intervals (無重疊區間)
 * 難度：中等 (Medium)
 * 描述：計算需要移除的最少區間數量，以使剩餘區間無重疊。
 * * 時間複雜度：O(NlogN) - 主要耗時在排序。
 * 空間複雜度：O(1) - 原地排序並使用常數空間（若不計排序所需的堆疊空間）。
 * * 優化思路：
 * 1. 按結束時間 (end time) 升序排序。
 * 2. 初始化 `preEnd` 為第一個區間的結束時間，並累計可保留的區間數。
 * 3. 遍歷區間，若下一個區間的起始時間 >= `preEnd`，則保留該區間並更新 `preEnd`。
 * 4. 答案為總區間數減去保留的區間數。
 */

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // 按區間的結束時間進行排序 (Greedy 策略)
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 1; // 記錄能保留的最大區間數
        int preEnd = intervals[0][1];

        for (size_t i = 1; i < intervals.size(); ++i) {
            // 如果下一個區間的起始時間 >= 前一個區間的結束時間，則不重疊
            if (intervals[i][0] >= preEnd) {
                count++;
                preEnd = intervals[i][1];
            }
        }

        // 需要移除的數量 = 總數 - 可保留的最大數量
        return intervals.size() - count;
    }
};
