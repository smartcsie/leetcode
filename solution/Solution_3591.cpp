/**
 * 題目：3591. Check if Any Element Has Prime Frequency (檢查是否存在質數頻率)
 * 難度：簡單 (Easy)
 * 描述：判斷陣列中是否有元素的出現次數為質數。
 *
 * 時間複雜度：O(N+KloglogK)
 * 空間複雜度：O(K)
 *
 * 解法思路：
 * 1. 效率提升：遍歷統計頻率的陣列而非原始陣列，減少重複判斷。
 * 2. 空間最佳化：將 `isPrime` 宣告為靜態以避免重複執行篩法。
 */

class Solution {
private:
    bool isPrime(int n){
        if(n < 2) return false;
        if(n == 2 || n == 3) return true;
        if(n % 2 == 0 || n % 3 == 0) return false; 
        for(int i = 5; i * i <= n; i += 6) {
            if(n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        vector<int> counts(101);
        for(const int& x : nums) counts[x]++;
        for(int i = 0; i <= 100; i++) {
            if(counts[i] && isPrime(counts[i])) return true;
        }
        return false;
    }
};