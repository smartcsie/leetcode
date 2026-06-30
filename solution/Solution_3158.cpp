/**
 * 題目：3158. Find the XOR of Numbers Which Appear Twice (找出出現兩次數字的 XOR 值)
 * 難度：簡單 (Easy)
 * 描述：在陣列中找出所有出現兩次的數字，並返回它們的 XOR 結果。
 * * 時間複雜度：O(N)，N 為陣列長度。
 * 空間複雜度：O(1)，使用固定大小 51 的陣列。
 * * 優化思路：
 * 1. 使用棧陣列 (int count[51]) 避免 vector 在堆上配置記憶體的開銷。
 * 2. 累加計數的同時判斷是否為第二次出現，減少後續遍歷次數。
 */

#include <vector>

class Solution {
public:
    int duplicateNumbersXOR(std::vector<int>& nums) {
        // 使用 stack 上的陣列，比 vector 更快且無堆疊配置開銷
        // 題目限制數值範圍為 1 到 50，故陣列大小設為 51
        int count[51] = {0};
        int res = 0;
        
        for (const int num : nums) {
            count[num]++;
            // 當數字出現第二次時，立即進行 XOR，這樣就不需要第二次遍歷
            if (count[num] == 2) {
                res ^= num;
            }
        }
        
        return res;
    }
};
