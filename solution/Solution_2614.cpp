/**
 * 題目：2614. Prime In Diagonal (對角線上的質數)
 * 難度：簡單 (Easy)
 * 描述：在二維矩陣的兩條對角線上，找出最大的質數。
 *
 * 時間複雜度：O(N*sqrt(M)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 減少重複判斷：處理矩陣中心交點時，確保僅對該元素執行一次質數判斷。
 * 2. 邏輯短路：結合 `x > maxPrime` 與 `isPrime` 函式，若已大於目前最大質數才進行昂貴的運算。
 */

class Solution {
private:
    bool isPrime(int n) {
        if(n < 2) return false;
        if(n == 2 || n == 3) return true;
        if(n % 2 == 0 || n % 3 ==0) return false;
        for(int i = 5; i*i <= n; i += 6) {
            if( n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int ans; 
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(isPrime(nums[i][i])) ans = max(ans, nums[i][i]);
            if(isPrime(nums[i][n - 1 - i])) ans = max(ans, nums[i][n - 1 - i]);
        }
        return ans;
    }
};
