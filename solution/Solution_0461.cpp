/**
 * 題目：461. Hamming Distance (漢明距離)
 * 難度：簡單 (Easy)
 * 描述：計算兩個整數之間的漢明距離（即二進位表示中位元不同的位置數量）。
 * 
 * 時間複雜度：O(k)，其中 k 為兩個數字中 1 的總數量（最快）。
 * 空間複雜度：O(1)。
 * 
 * 解法思路：
 * 1. XOR 運算：x ^ y 的結果中，每一位為 1 代表該位置的 bits 不同。
 * 2. 統計 1 的個數：使用 Brian Kernighan's Algorithm，每次執行 xorVal &= (xorVal - 1) 
 *    都能精準地消除最右側的一個 1，直到 xorVal 變成 0 為止。
 */

class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorVal = x ^ y;
        int count = 0;
        
        while (xorVal > 0) {
            // 每執行一次，消除一個 1
            xorVal &= (xorVal - 1);
            count++;
        }
        
        // 修正：直接回傳 count 即可
        return count;
    }
};
