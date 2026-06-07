/**
 * 題目：128. Longest Consecutive Sequence (最長連續序列)
 * 難度：困難 (Hard)
 * 描述：在 O(N) 時間內找出數字連續的最長序列。
 * * 時間複雜度：O(N) - 每個數字最多處理常數次。
 * 空間複雜度：O(N) - 使用雜湊表儲存每個數的連續區間長度。
 * * 優化思路：
 * 1. 雜湊表 `m` 儲存每個數所屬區間的長度。
 * 2. 當新數 `num` 加入時，檢查 `num-1` 與 `num+1` 是否存在。
 * 3. 若存在，則合併左右兩邊的區間長度，並更新區間兩端的長度記錄。
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        // 使用 unordered_map 儲存連續區間長度
        unordered_map<int, int> m;
        
        for (int num : nums) {
            // 如果數字已存在，跳過以避免重複計算
            if (m.find(num) != m.end()) continue;
            
            // 查詢左右相鄰數的區間長度
            int left = m.count(num - 1) ? m[num - 1] : 0;
            int right = m.count(num + 1) ? m[num + 1] : 0;
            
            // 計算合併後的總長度
            int sum = left + right + 1;
            m[num] = sum;
            res = max(res, sum);
            
            // 更新區間兩端點的長度資訊
            // 只有區間端點才需要更新，中間值其實無需維護
            m[num - left] = sum;
            m[num + right] = sum;
        }
        
        return res;
    }
};
