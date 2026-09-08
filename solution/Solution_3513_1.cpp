/**
 * 題目：3513. Number of Unique XOR Triplets I
 * 難度：中等 (Medium)
 * 描述：計算陣列中不同 XOR 三元組的數量。
 *
 * 時間複雜度：O(logN)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （數學，答案為 2^(floor(log2(n))+1)）：
 * 用 log2 計算最高位，結果為 2 的冪次方。
 */
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return n;
        return 1 << (static_cast<int>(log2(n)) + 1);
    }
};