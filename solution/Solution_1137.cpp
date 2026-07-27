/**
 * 題目：1137. N-th Tribonacci Number (第 N 個泰波那契數)
 * 難度：簡單 (Easy)
 * 描述：計算 T(n) = T(n-1) + T(n-2) + T(n-3)，其中 T(0)=0, T(1)=1, T(2)=1。
 * * 時間複雜度：O(N) - 進行一次線性迭代。
 * 空間複雜度：O(1) - 僅使用三個變數進行狀態轉移。
 */

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        int n0 = 0, n1 =1, n2 =1, n3 = 0;
        for(int i = 3; i <= n; i++) {
            n3 = n2 + n1 + n0;
            n0 = n1;
            n1 = n2;
            n2 = n3;
        }
        return n3;
    }
};
