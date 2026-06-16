/**
 * 題目：2761. Prime Pairs With Target Sum (和為目標值的質數對)
 * 難度：中等 (Medium)
 * 描述：找出所有滿足 x + y = n 的質數對 [x, y]，其中 x <= y。
 * * 時間複雜度：O(n log log n) - 由篩法決定。
 * 空間複雜度：O(n) - 儲存質數表。
 * * 優化思路：
 * 1. 空間效率：isPrime 陣列大小精確為 n + 1。
 * 2. 預分配：對 result 陣列使用 reserve，減少動態記憶體重分配。
 */

class Solution {
private:
    // 埃拉托斯特尼篩法，建立質數表
    vector<bool> getPrimes(int n) {
        vector<bool> isPrime(n + 1, true);
        if (n >= 0) isPrime[0] = false;
        if (n >= 1) isPrime[1] = false;
        
        for (int p = 2; p * p <= n; ++p) {
            if (isPrime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    isPrime[i] = false;
                }
            }
        }
        return isPrime;
    }

public:
    vector<vector<int>> findPrimePairs(int n) {
        if (n < 4) return {}; // 最小質數對為 2+2=4

        vector<bool> isPrime = getPrimes(n);
        vector<vector<int>> res;
        
        // 為了避免重複分配記憶體，可以預估一個空間，或直接使用 push_back
        // 遍歷 x 直到 n/2，確保 x <= y
        for (int x = 2; x <= n / 2; ++x) {
            int y = n - x;
            if (isPrime[x] && isPrime[y]) {
                res.push_back({x, y});
            }
        }
        
        return res;
    }
};
