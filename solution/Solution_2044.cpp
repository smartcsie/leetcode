/**
 * 題目：2044. Count Number of Maximum Bitwise-OR Subsets
 * 難度：Medium
 * 描述：給定整數陣列 nums，找出子集（可由刪除部分元素得到，以索引區分）能得到的
 *       最大按位或（bitwise OR）值，並回傳有多少個不同的子集能達到這個最大值。
 *
 * 分類主題：bit-manipulation-or
 * 技巧：以 OR 結果當狀態的 DP, 由大到小更新避免同一個數字被重複使用, 全部元素的 OR 就是最大值
 *
 * 時間複雜度：O(n * M)，M 為 OR 值的範圍（< 2^17），本題 n 很小
 * 空間複雜度：O(M)，dp 陣列大小 2^17
 *
 * 解法思路：DP，狀態是「OR 的結果」
 * 1. OR 只會讓位元越來越多（單調不減），所以子集能達到的最大 OR，
 *    就是「全部元素」的 OR。答案就是 OR 等於這個值的子集數量。
 * 2. 定義 dp[v] = 目前已處理的元素中，OR 結果恰為 v 的子集數量。
 *    初始 dp[0] = 1：空子集的 OR 是 0。
 * 3. 處理每個 num：既有的每個 OR 值 i，把 num 加進去後變成 i | num，
 *    所以 dp[i | num] += dp[i]（原本不選 num 的子集仍留在 dp[i]，不用額外處理）。
 * 4. i 要由大到小掃：
 *    i | num >= i，寫入的位置一定在 i 之後或等於 i，
 *    由大到小掃可以保證「這一輪剛寫入的值」不會在同一輪被再讀一次，
 *    也就是每個 num 對每個子集只貢獻一次（類似 0/1 背包由後往前）。
 * 5. max 記錄目前已處理元素的 OR，出現過的 OR 值一定 <= max，
 *    所以只需要掃 0 ~ max。全部處理完時，max 就是全部元素的 OR。
 * 6. 答案 dp[max]。nums[i] 至少為 1，所以 max >= 1，
 *    dp[0] 代表的空子集不會被算進答案。
 * 7. dp 大小取 2^17：我記得 nums[i] <= 10^5 < 2^17，任意數字的 OR 也不會超過 2^17 - 1。
 */
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max = 0;                     // 目前已處理元素的 OR（也是 dp 需要掃描的上界）
        vector<int> dp(1 << 17, 0);      // dp[v]：OR 結果恰為 v 的子集數量
        dp[0] = 1;                       // 空子集的 OR 為 0

        for (int num : nums) {
            // 由大到小：確保這一輪新寫入的 dp 值不會被同一輪再次讀取
            for (int i = max; i >= 0; i--) {
                dp[i | num] += dp[i];    // 把 num 加進 OR 為 i 的所有子集
            }
            max |= num;                  // 更新目前的 OR 上界
        }
        return dp[max];                  // OR 等於全部元素 OR 的子集數量
    }
};