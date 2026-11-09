/**
 * 題目：2348. Number of Zero-Filled Subarrays
 * 難度：中等 (Medium)
 * 描述：給定一個整數陣列，計算所有只包含 0 的子陣列數量。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （Consecutive Count Contribution）：
 * 每遇到一個 0，以當前位置結尾的全零子陣列數量等於連續 0 的長度 zeros。
 * 遇到非零元素時重置 zeros 為 0。
 *
 * 例如連續 k 個 0，貢獻的子陣列數為 1 + 2 + ... + k = k*(k+1)/2，
 * 透過每步累加 zeros 自然得到此結果，不需要額外計算等差數列。
 *
 * 範例：nums = [0, 0, 0]
 *   x=0: zeros=1, ans=1  → "0"
 *   x=0: zeros=2, ans=3  → "0","0","00"
 *   x=0: zeros=3, ans=6  → "0","0","0","00","00","000"
 */
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long zeros = 0;
        long long ans = 0;
        for (const int& x : nums) {
            zeros = (x == 0) ? zeros + 1 : 0;
            ans += zeros;
        }
        return ans;
    }
};
