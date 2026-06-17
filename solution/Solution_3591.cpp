/**
 * 題目：3591. Check if Any Element Has Prime Frequency (檢查是否存在質數頻率)
 * 難度：簡單 (Easy)
 * 描述：判斷陣列中是否有元素的出現次數為質數。
 * * 時間複雜度：O(N + K log log K)，N 為陣列長度，K 為數值範圍。
 * 空間複雜度：O(K)，用於存儲頻率與質數標記。
 * * 優化思路：
 * 1. 效率提升：遍歷統計頻率的陣列而非原始陣列，減少重複判斷。
 * 2. 空間最佳化：將 `isPrime` 宣告為靜態以避免重複執行篩法。
 */

class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        int n = 100;
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int p = 2; p * p <= n; ++p) {
            if (isPrime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    isPrime[i] = false;
                }
            }
        }
        int seen[101] = {false};
        for(const int& num : nums) {
            seen[num]++;
        }
        for(const int& num : nums) {
            if(isPrime[seen[num]]) return true;
        }
        return false;
    }
};
