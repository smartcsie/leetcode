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
    int nthSuperUglyNumber(int n, std::vector<int>& primes) {
        int k = primes.size();
        vector<int> idx(k, 0);
        vector<long> uglys{1};
        while(uglys.size() < n) {
            vector<long> next(k);
            for(int i = 0; i < k ; i++) {
                next[i] = uglys[idx[i]] * static_cast<long>(primes[i]);
            }
            long mn = *min_element(next.begin(), next.end());
            uglys.push_back(mn);
            for(int i = 0; i < k ; i++) {
                if(mn == next[i]) idx[i]++;
            }
        }
        return uglys.back();
    }
};
