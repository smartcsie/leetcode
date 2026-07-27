/**
 * 題目：3688. Bitwise OR of Even Numbers in an Array (陣列中偶數的位元或)
 * 難度：簡單 (Easy)
 * 描述：計算陣列中所有偶數的 OR 結果。
 * * 時間複雜度：O(N)，N 為陣列長度。
 * 空間複雜度：O(1)。
 * * 優化思路：
 * 1. 簡潔判斷：使用 (num & 1) == 0 判斷偶數，維持 O(N) 一次遍歷。
 * 2. 效率考量：直接使用值傳遞 `int num` 在處理基礎型別時通常與引用傳遞 `const int&` 在效能上無異，且更簡潔。
 */

class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int result = 0;
        for(const int& num : nums) {
            if((num & 1) == 0) {
                result |= num;
            }
        }
        return result;
    }
};
