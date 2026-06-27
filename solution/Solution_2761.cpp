class Solution {

public:
    vector<vector<int>> findPrimePairs(int n) {
        bitset<1000001> isPrime;
        isPrime.set();
        isPrime.reset(0);
        isPrime.reset(1);
        for(int p = 2; p * p <= n; p++) {
            if(isPrime[p]) {
                for(int i = p * p;  i <= n; i += p) {
                    isPrime.reset(i);
                }
            }
        }
        vector<vector<int>> res;
        for(int i = 1; i <= n / 2; i++) {
            if(isPrime[i] && isPrime[n - i]) res.push_back({i, n - i});
        }
        return res;
    }
};
