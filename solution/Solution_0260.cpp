/**
 * 題目：260. Single Number III (只出現一次的數字 III)
 * 難度：中等 (Medium)
 * 描述：一個陣列中除了兩個數字只出現一次外，其他數字都出現兩次。找出這兩個數字。
 *
 * 時間複雜度：O(N) - 遍歷陣列兩次。
 * 空間複雜度：O(1) - 僅使用幾個整數變數。
 *
 * 解法思路：
 * (位元分組法)：
 * 1. 將陣列所有數字進行 XOR，得到 `xor_all`。因為出現兩次的數字 XOR 後為 0，
 * 所以 `xor_all` 最終等於 `a ^ b` (a, b 為那兩個只出現一次的數字)。
 * 2. 找到 `xor_all` 中任意一個為 1 的位元 (diff_bit)。
 * 這個位元代表 a 與 b 在該位元上是不同的。
 * 3. 再次遍歷陣列，根據 `num & diff_bit` 是否為 0，將陣列分為兩組：
 * - 包含 a 的一組
 * - 包含 b 的一組
 * (出現兩次的數字會被分到同一組並相互抵消，最後每組的 XOR 結果即為 a 和 b)
 */

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorAll = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        int differBit = 1;
        while((xorAll & differBit) == 0) {
            differBit <<= 1; 
        }
        int a = 0 , b = 0;
        for(const int& num : nums) {
            if(differBit & num) {
                a ^= num;
            } else {
                b ^= num;
            }
        }
        return {a, b};
    }
};
