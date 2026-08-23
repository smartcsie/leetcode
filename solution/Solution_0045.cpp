/**
 * 題目：45. Jump Game II
 * 難度：中等 (Medium)
 * 分類主題：greedy-prefix-suffix
 * 描述：給定一個整數陣列 nums，從索引 0 出發，nums[i] 是在位置 i
 * 最多能往前跳幾步。求跳到最後一個索引所需的最少跳躍次數（保證一定
 * 能跳到）。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （Prefix/Suffix Greedy，這題的核心是「隱式 BFS」：不用真的一步步
 * 模擬每次跳到哪，而是用「目前這一跳能到的範圍」跟「下一跳最遠能到
 * 哪裡」兩個邊界去推進，像是一層一層展開 BFS 的層數）：
 * 1. curEnd 代表「目前這一跳」能到達的最遠邊界（這一跳結束前，都算
 *    同一次跳躍次數內）；farthest 代表「如果現在開始準備下一跳」，
 *    從目前掃過的所有位置裡，下一跳最遠能到哪裡。
 * 2. 掃描陣列（不用掃到最後一個元素，因為到達最後一個就結束了）：
 *    每個位置 i，更新 farthest = max(farthest, i + nums[i])（這個
 *    位置如果是下一跳的起點，最遠能跳到哪）。
 * 3. **關鍵時機**：當 i 剛好走到 curEnd（代表「這一跳」的範圍已經
 *    掃描完了，該決定要不要跳下一步），跳躍次數 +1，並把 curEnd
 *    更新成 farthest（這一跳結束後，下一跳的範圍邊界）。
 * 4. 這個技巧不用真的知道「在 curEnd 這個範圍裡，具體從哪個位置跳」，
 *    因為只要 farthest 有更新到，就代表「範圍內某個位置」能跳到那麼
 *    遠，貪心地假設會選這個最優的跳法，最終次數一定最少。
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, curEnd = 0, farthest = 0;
        for (int i = 0; i < n - 1; ++i) {
            farthest = max(farthest, i + nums[i]);
            if (i == curEnd) {
                jumps++;
                curEnd = farthest;
            }
        }
        return jumps;
    }
};
