/**
 * 題目：1248. Count Number of Nice Subarrays
 * 描述：給你一個整數陣列 nums 和一個整數 k。如果某個連續子陣列中恰好有 k 個奇數數字，
 *       我們就稱其為「優美子陣列」。請返回該陣列中「優美子陣列」的總數量。
 * 
 * 解法思路：
 * 1. 等價轉換：求「恰好有 k 個奇數」的子陣列數量，可以轉換為：
 *    `atMost(k) - atMost(k - 1)`（最多有 k 個奇數的子陣列總數 減去 最多有 k-1 個奇數的子陣列總數）。
 * 2. 同向雙指針滑動視窗 (`numberOfSubarraysAtMost`)：
 *    - 利用 `l`（左指針）與 `r`（右指針）進行掃描。
 *    - 當條件允許（`k >= 0`）時，右指針 `r` 向右擴張，並累加當前以 `r` 為結尾的合法子陣列長度 `r - l`。
 *    - 當奇數額度超支（`k < 0`）時，左指針 `l` 向右收縮，釋放奇數額度直到恢復合法。
 * 3. 這種寫法將雙指針融合成單一迴圈，極具效率且簡潔。
 */


class Solution {
public:
    int numberOfSubarrays(std::vector<int>& nums, int k) {
        return numberOfSubarraysAtMost(nums, k) - numberOfSubarraysAtMost(nums, k - 1);
    }
private:
    int numberOfSubarraysAtMost(std::vector<int>& nums, int k) {
        int ans = 0;
        // 透過單一迴圈控制雙指針 l 與 r
        for (int l = 0, r = 0; r <= nums.size();) {
            if (k >= 0) {
                ans += (r - l);
                // 如果 r 已經走完陣列，結束迴圈
                if (r == nums.size()) {
                    break;
                }
                // 若遇到奇數，扣減可用的奇數額度 k
                if (nums[r] % 2 == 1) {
                    --k;
                }
                ++r;
            } else {
                // 額度不足時，收縮左邊界 l
                if (nums[l] % 2 == 1) {
                    ++k;
                }
                ++l;
            }
        }
        return ans;
    }
};
