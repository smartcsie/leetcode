// 題目：1512. Number of Good Pairs
// 難度：Easy
// 時間複雜度：O(n + V)，V = 值域大小（100）
// 空間複雜度：O(1)（固定 101 格的計數陣列）
// 分類主題：array / hash-table / math
// 技巧：計數陣列 + 組合數 C(k, 2) = k * (k - 1) / 2

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // 題目限制 1 <= nums[i] <= 100，直接用數值當索引
        // counts[v] = 數值 v 出現的次數；n <= 100，uint8_t（0~255）足夠
        array<uint8_t, 101> counts{};
        for(const int& x : nums) {
            counts[x]++;
        }

        int sum = 0;
        for(int x = 1; x <= 100; x++) {
            // 同一個數值出現 k 次，任選 2 個位置組成一對：C(k, 2) = k * (k - 1) / 2
            // 例：k = 3 -> 3 對（(0,1)、(0,2)、(1,2)）
            // 注意：uint8_t 運算時會先提升成 int，所以 counts[x] = 0 時
            //       (counts[x] - 1) 是 -1 而不是 255，乘出來是 0，不會出錯
            sum += counts[x] * (counts[x] - 1) / 2;
        }
        return sum;
    }
};