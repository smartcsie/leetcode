/**
 * 題目：2595. Number of Even and Odd Bits (偶數與奇數位數)
 * 難度：簡單 (Easy)
 * 描述：給定一個正整數 n，回傳一個陣列 [even, odd]，分別代表其二進位表示中
 * 位元為 1 的「偶數位」與「奇數位」總數。
 * * 時間複雜度：O(log N) - 對於整數 n，位元數為 log2(n)。
 * 空間複雜度：O(1) - 僅儲存兩個結果值的陣列。
 * * 優化思路：
 * 利用右移運算子 `>>=` 逐位檢查，並利用 `i ^= 1` 在 0 與 1 之間切換索引，
 * 達成無需額外條件判斷即可切換統計位置的高效邏輯。
 */

class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> res(2);
        for(int i = 0; n > 0; n >>= 1, i ^= 1) {
            res[i] += n&1;
        }
        return res;
    }
};
