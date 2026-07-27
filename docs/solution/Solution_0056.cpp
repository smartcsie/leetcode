/**
 * 題目：56. Merge Intervals (合併區間)
 * 難度：中等 (Medium)
 * 描述：將所有重疊的區間合併為一個不重疊的區間陣列。
 * * 時間複雜度：O(N log N) - 主要開銷在於排序。
 * 空間複雜度：O(log N) - 取決於排序演算法的堆疊空間。
 * * 優化思路：
 * 1. 將區間依據「起始點」排序。
 * 2. 遍歷排序後的區間，若當前區間的起始點小於等於結果集中最後一個區間的結束點，
 * 則兩者重疊，更新結束點為兩者較大者。
 * 3. 否則，表示不重疊，直接推入新的區間。
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& v1,const vector<int>& v2){
            if(v1[0] != v2[0]) {
                return v1[0] < v2[0];
            }
            return v1 < v2;
        });
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size();i++) {
            if(intervals[i][0]  <= res.back()[1]) {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
