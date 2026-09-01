/**
 * 題目：435. Non-overlapping Intervals (無重疊區間)
 * 難度：中等 (Medium)
 * 描述：計算需要移除的最少區間數量，以使剩餘區間無重疊。
 *
 * 時間複雜度：O(NlogN)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 按結束時間 (end time) 升序排序。
 * 2. 初始化 `preEnd` 為第一個區間的結束時間，並累計可保留的區間數。
 * 3. 遍歷區間，若下一個區間的起始時間 >= `preEnd`，則保留該區間並更新 `preEnd`。
 * 4. 答案為總區間數減去保留的區間數。
 */

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>>& itvs = intervals;
        sort(itvs.begin(), itvs.end(), [](const auto& a, const auto& b){
            return a[1] < b[1]; 
        });
        int ans = 0;
        int prevEnd = itvs[0][1];
        for(int i = 1; i < itvs.size(); i++) {
            if(prevEnd <= itvs[i][0]) prevEnd = itvs[i][1];
            else ans++;
        }
        return ans;
    }
};
