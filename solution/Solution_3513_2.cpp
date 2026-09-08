/**
 * 題目：3513. Number of Unique XOR Triplets I
 * 難度：中等 (Medium)
 * 描述：計算陣列中不同 XOR 三元組的數量。
 *
 * 時間複雜度：O(logN)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （位元左移找最小的 2 的冪次方大於 n）：
 * 從 1 開始不斷左移直到超過 n，即為答案，與 log2 版等價。
 */
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return n;
        int ans = 1;
        while(n > 0) {
            ans <<= 1;
            n >>= 1;
        }
        return ans;
    }
};