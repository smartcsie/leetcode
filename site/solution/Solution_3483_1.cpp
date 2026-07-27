/**
 * 題目：3483. Unique 3-Digit Even Numbers
 * 難度：簡單 (Easy)
 * 描述：使用給定的 digits 陣列中的數字組成不重複的三位數偶數。
 * * 時間複雜度：O(P(N, 3))，即排列組合數量級，N 為 digits 長度。
 * 空間複雜度：O(N)，用於遞迴堆疊與標記陣列。
 * * 優化思路：
 * 1. 使用回溯法 (Backtracking) 窮舉所有可能的排列。
 * 2. 使用 visited 陣列避免重複使用同一索引的數字。
 * 3. 使用 unordered_set 自動處理數值上的重複，確保結果唯一。
 * 4. 位元檢查 (cur[2] & 1) == 0 判斷偶數，首位判斷 digits[i] != 0。
 */

class Solution {
private:
    void backtrack(const std::vector<int>& digits, std::vector<int>& cur, std::vector<bool>& visited, std::unordered_set<int>& res) {
        if(cur.size() == 3) {
            // 檢查末位是否為偶數
            if((cur[2] & 1) == 0) {
                res.insert(cur[0] * 100 + cur[1] * 10 + cur[2]);
            }
            return;
        }
        
        for(int i = 0; i < digits.size(); i++) {
            // 1. 首位不能為 0
            if(cur.empty() && digits[i] == 0) continue;
            // 2. 避免使用已用過的數字
            if(visited[i]) continue;
            // 3. 剪枝優化：如果當前數字與前一個相同且前一個未被訪問，跳過以避免重複組合
            if(i > 0 && digits[i] == digits[i-1] && !visited[i-1]) continue;
            
            visited[i] = true;
            cur.push_back(digits[i]);
            
            backtrack(digits, cur, visited, res);
            
            cur.pop_back();
            visited[i] = false;
        }
    }

public:
    int totalNumbers(std::vector<int>& digits) {
        // 先排序以利於後續的重複元素剪枝
        std::vector<int> sorted_digits = digits;
        std::sort(sorted_digits.begin(), sorted_digits.end());
        
        std::unordered_set<int> res;
        std::vector<bool> visited(sorted_digits.size(), false);
        std::vector<int> cur;
        
        backtrack(sorted_digits, cur, visited, res);
        return static_cast<int>(res.size());
    }
};
