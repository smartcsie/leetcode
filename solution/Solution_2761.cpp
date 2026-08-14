/**
 * 註解：待補充
 */
class Solution {

public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        for(int p = 2; p * p <= n; p++) {
            if(isPrime[p]) {
                for(int i = p * p; i <= n; i += p) {
                    isPrime[i] = false;
                }
            }
        }
        vector<vector<int>> ans;
        for(int x = 1; x <= n / 2; x++) {
            int y = n - x; 
            if(isPrime[x] && isPrime[y]) ans.push_back({x, y});
        }
        return ans;
    }
};