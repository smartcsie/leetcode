/**
 * 題目：1748. Sum of Unique Elements (唯一元素的和)
 * 難度：簡單 (Easy)
 * 描述：計算陣列中只出現過一次的元素的總和。
 * * 時間複雜度：O(N) - 遍歷一次陣列。
 * 空間複雜度：O(K) - K 為數字範圍（在此題為 100）。
 * * 優化思路：
 * 1. 原本使用 `unordered_map` 有較高的雜湊開銷。
 * 2. 由於題目限制數字範圍在 [1, 100]，使用 `int count[101]` 陣列可大幅提升速度。
 */

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        // 使用固定大小的陣列取代雜湊表，效能更好
        int count[101] = {0}; 
        int sum = 0;
        
        for (const int& num : nums) {
            count[num]++;
            
            // 第一次出現時加入
            if (count[num] == 1) {
                sum += num;
            } 
            // 第二次出現時移除（即變為不再唯一）
            else if (count[num] == 2) {
                sum -= num;
            }
            // 若超過兩次則忽略（維持 sum 不變）
        }
        
        return sum;
    }
};
