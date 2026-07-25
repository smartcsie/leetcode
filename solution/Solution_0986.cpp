/**
 * 題目：986. Interval List Intersections
 * 描述：給定兩個由「已排序且不相交」的區間列表 firstList 和 secondList，
 *       返回這兩個區間列表的交集。
 * 
 * 解法思路（雙指標法 Two Pointers）：
 * 1. 區間交集的核心數學邏輯：
 *    - 兩個區間 `[A_start, A_end]` 與 `[B_start, B_end]` 的交集範圍為：
 *      `start = max(A_start, B_start)`
 *      `end = min(A_end, B_end)`
 *    - 當且僅當 `start <= end` 時，代表交集區間確實存在。
 * 2. 指標推進策略：
 *    - 比較兩個區間的「結束位置（end）」。結束位置較早的那個區間已經不可能和下一個區間產生交集了，
 *      因此結束位置較小的那個指針可以向後移動（`i++` 或 `j++`）。
 */

class Solution {
public:
    std::vector<std::vector<int>> intervalIntersection(std::vector<std::vector<int>>& firstList, std::vector<std::vector<int>>& secondList) {
        std::vector<std::vector<int>> ans;
        int i = 0, j = 0;
        int m = firstList.size();
        int n = secondList.size();
        // 若其中一個列表為空，直接返回空陣列
        if (m == 0 || n == 0) return {};
        while (i < m && j < n) {
            // 計算交集的起點與終點
            int start = std::max(firstList[i][0], secondList[j][0]);
            int end = std::min(firstList[i][1], secondList[j][1]);
            // 若起點小於等於終點，代表交集有效，加入結果中
            if (start <= end) {
                ans.push_back({start, end});
            }
            // 誰的結束時間比較早，誰的指標就先往後走（因為它已經不可能跟後續區間相交了）
            if (firstList[i][1] < secondList[j][1]) {
                i++;
            } else {
                j++;
            }
        }
        return ans;
    }
};
