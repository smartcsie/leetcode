/**
 * 題目：268. Missing Number
 * 難度：簡單 (Easy)
 * 描述：給定一個包含 n 個相異數字、取值範圍為 [0, n] 的陣列 nums，
 * 找出 [0, n] 這個範圍內唯一缺少的那個數字。
 *
 * 分類主題：bit-manipulation-xor
 * 技巧：XOR 成對抵消, 索引與數值一起 XOR, 初始值設為 n
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：XOR 成對抵消
 * 1. XOR 的性質：a ^ a = 0、a ^ 0 = a，且滿足交換律與結合律。
 *    所以一堆數字 XOR 起來，出現兩次的會全部消掉，只剩出現一次的。
 * 2. 完整的集合是 0～n，現在的 nums 缺了其中一個數字。
 *    把「0～n 全部」和「nums 的所有元素」放在一起 XOR：
 *    除了缺失的那個數字只出現一次，其他數字都恰好出現兩次，會被消掉。
 * 3. 實作上，迴圈同時 XOR 索引 i 與 nums[i]，一次處理 0～n-1 的索引
 *    和所有元素；索引裡沒有 n，所以答案的初始值直接設成 n 補上。
 * 4. 最後 ans 就是缺失的數字。
 *
 * 備註：和數學解（n(n+1)/2 - sum）相比，XOR 不會有加總溢位的疑慮，
 *       也不需要修改輸入陣列（Cyclic Sort 解法會改動 nums）。
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorVal = 0;
        for(int i = 0; i <= n; i++) xorVal ^= i;
        for(const int& x : nums) xorVal ^= x;
        return xorVal;
    }
};