/**
 * 題目：313. Super Ugly Number
 * 難度：中等 (Medium)
 * 描述：找到第 n 個「超級醜數」，其質因數僅包含在給定的 primes 陣列中。
 * * 優化重點：
 * 1. 多指標法 (Multi-pointers)：針對每個質數維護一個指標，對應已產生的醜數序列。
 * 2. 避免重複：在每輪選取最小值時，若多個質數乘積相同，則同步推進所有對應指標。
 * 3. 型別防護：使用 long 避免計算過程中的整數溢位。
 */

class Solution {
public:
    int nthSuperUglyNumber(int n, std::vector<int>& primes) {
        const int k = primes.size();
        std::vector<int> indices(k, 0); // 維護 k 個指標
        std::vector<long> uglyNums{1}; // 儲存已找到的醜數
        
        while (uglyNums.size() < n) {
            std::vector<long> nexts(k);
            // 計算當前各指標乘以對應質數的候選值
            for (int i = 0; i < k; ++i) {
                nexts[i] = uglyNums[indices[i]] * static_cast<long>(primes[i]);
            }
            
            // 找出本次的最小候選值
            const long next = *std::ranges::min_element(nexts);
            
            // 同步推進指標，若候選值相等則全部推進，避免重複
            for (int i = 0; i < k; ++i) {
                if (next == nexts[i]) {
                    indices[i]++;
                }
            }
            uglyNums.push_back(static_cast<int>(next));
        }
        
        return static_cast<int>(uglyNums.back());
    }
};
