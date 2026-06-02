/**
 * 題目：739. Daily Temperatures (每日溫度)
 * 難度：中等 (Medium)
 * 描述：計算每一天需要等幾天才能等到氣溫更高的一天。
 * * 時間複雜度：O(N) - 每個索引最多被壓入和彈出棧一次。
 * 空間複雜度：O(N) - 棧在最壞情況下會儲存 N 個索引。
 * * 優化思路：
 * 1. 使用「單調遞減棧」：棧底到棧頂儲存索引，其對應的溫度是遞減的。
 * 2. 從右往左遍歷：確保我們總是能快速找到右側最近的更高溫索引。
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> stk;
        vector<int> ans(n, 0); // 初始化為 0，若找不到更高溫則維持 0
        
        // 從右往左遍歷
        for (int i = n - 1; i >= 0; --i) {
            // 彈出所有比當前溫度低或等於的索引，因為它們對當前位置來說沒有意義
            // 我們只需要找到第一個比當前溫度大的索引
            while (!stk.empty() && temperatures[stk.top()] <= temperatures[i]) {
                stk.pop();
            }
            
            // 若棧不為空，棧頂即為下一個更高溫度的索引
            if (!stk.empty()) {
                ans[i] = stk.top() - i;
            }
            
            // 將當前索引壓入棧中
            stk.push(i);
        }
        return ans;
    }
};
