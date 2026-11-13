// 題目：2441. Largest Positive Integer That Exists With Its Negative
// 難度：Easy
// 時間複雜度：O(n)
// 空間複雜度：O(1)（固定大小 1001 的陣列，與 n 無關）
// 分類主題：array / hash-table
// 技巧：bitmask 標記（用 1 表示見過正數，2 表示見過負數）

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        // count[v] 記錄絕對值為 v 的數字出現過哪些符號：
        //   bit 0 (值 1) = 出現過 +v
        //   bit 1 (值 2) = 出現過 -v
        //   值 3 = 正負都出現過
        // 題目保證 -1000 <= nums[i] <= 1000 且 nums[i] != 0，所以開 1001 格就夠
        // {} 讓所有元素初始化為 0
        array<uint8_t, 1001> count{};

        // 沒有任何數字同時有正負時，題目要求回傳 -1
        int mx = -1;

        for(const int& x : nums) {
            int idx = abs(x);                      // 以絕對值當索引

            // 正數標 1，負數標 2；用 |= 累積，重複出現同符號也不會影響結果
            count[idx] |= (x > 0) ? 1 : 2;

            // 兩種符號都見過（1 | 2 == 3），且比目前答案大就更新
            // 一旦 == 3，無論 +v 或 -v 是後出現的，都會在第二個出現時當下判斷到
            if(count[idx] == 3 && idx > mx) mx = idx;
        }
        return mx;
    }
};