/**
 * 題目：2485. Find the Pivot Integer
 * 難度：簡單 (Easy)
 * 描述：找出 x 使得 1 到 x 的總和等於 x 到 n 的總和。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （線性搜尋）：
 * 從 n/2 開始往上搜尋，利用等差數列公式驗證左右總和是否相等。
 */
class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1) return 1;
        for(int x = n / 2 ; x < n; x++) {
            if( (1 + x) * x / 2 == (x + n) * (n - x + 1) / 2 ) return x; 
        }
        return -1;
    }
};