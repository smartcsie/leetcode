/**
 * 題目：3556. Sum of Largest Prime Substrings
 * 難度：中等 (Medium)
 * 描述：在字串 s 中找出所有子字串所代表的質數，並計算前三大相異質數之和。
 *
 * 時間複雜度：O(N^2*sqrt(M)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 使用 6k±1 試除法優化質數判斷。
 * 2. 累加生成數字避免 substr() 與 stoll() 的高額開銷。
 * 3. 維護前三大唯一值，確保重複發現的質數不會影響累加結果。
 */

#define ll long long 
class Solution {
private:
    void update(ll val, ll& mx1, ll& mx2 , ll& mx3) {
        if(val == mx1 || val == mx2 || val == mx3) return;
        if(val > mx1) {
            mx3 = mx2;
            mx2 = mx1;
            mx1 = val;
        } else if(val > mx2) {
            mx3 = mx2;
            mx2 = val;
        } else if(val > mx3) {
            mx3 = val;
        }
    }
    bool isPrime(ll& n) {
        if(n < 2) return false;
        if(n == 2 || n == 3) return true;
        if(n % 2 == 0 || n % 3 == 0) return false;
        for(ll x = 5; x * x <= n; x += 6) {
            if(n % x == 0 || n % (x + 2) == 0) return false;
        }
        return true;
    }
public:
    long long sumOfLargestPrimes(string s) {
        ll mx1 = 0, mx2 = 0, mx3 = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            for(int j = 1; j <= n - i; j++) {
                string str = s.substr(i, j);
                ll val = stoll(str);
                if(isPrime(val)) update(val, mx1, mx2, mx3);
            }
        }
        return mx1 + mx2 + mx3;
    }
};