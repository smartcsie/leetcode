/**
 * 題目：461. Hamming Distance
 * 難度：簡單 (Easy)
 * 描述：計算兩個整數對應二進位位元不同的個數。
 *
 * 時間複雜度：O(1)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （Brian Kernighan's Algorithm）：
 * XOR 找出不同位元，再用 n &= (n-1) 逐一消除最低位的 1 並計數。
 */
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int count = 0;
        while(z > 0) {
            z = z & (z - 1);
            count++;
        }
        return count;
    }
};