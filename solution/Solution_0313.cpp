/**
 * 題目：313. Super Ugly Number
 * 難度：中等 (Medium)
 * 描述：找到第 n 個「超級醜數」，其質因數僅包含在給定的 primes 陣列中。
 * 優化重點：
 * 1. 多指標法 (Multi-pointers)：針對每個質數維護一個指標，對應已產生的醜數序列。
 * 2. 避免重複：在每輪選取最小值時，若多個質數乘積相同，則同步推進所有對應指標。
 * 3. 型別防護：使用 long 避免計算過程中的整數溢位。
 *
 * 時間複雜度：O(N*K)
 * 空間複雜度：O(N+K)
 */

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m =  primes.size();
        vector<int> idx(m, 0);
        vector<long> ans(n, LONG_MAX);
        ans[0] = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) ans[i] = min(ans[i], ans[idx[j]] * primes[j]);
            for(int j = 0; j < m; j++) if(ans[i] == ans[idx[j]] * primes[j]) idx[j]++;
        }
        return static_cast<int>(ans.back());
    }
};