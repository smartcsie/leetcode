/**
 * 題目：2044. Count Number of Maximum Bitwise-OR Subsets
 * 難度：中等 (Medium)
 * 分類主題：backtracking-combination
 * 描述：給定一個非負整數陣列 nums，求有幾個「子集合」的所有元素 OR
 * 起來，能達到「整個陣列全部元素 OR 起來」的最大值。
 *
 * 時間複雜度：O(N * 2^N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （Bitmask 窮舉，跟前一版的 DFS 回溯是完全等價的邏輯，只是用「二進位
 * 遮罩」取代遞迴呼叫來列舉每一種子集合，是回溯轉迭代的經典手法）：
 * 1. 先算出 target：把全部元素 OR 起來，這就是任何子集合能達到的
 *    OR 最大值上限（子集合是全陣列的子集，OR 只會越加越多或持平，
 *    絕對不會超過「全部都選」的結果）。
 * 2. **核心技巧**：n 個元素的每一種子集合，都可以對應到一個 n 位元
 *    的二進位數字 mask（0 到 2^n - 1），mask 的第 i 個 bit 是 1 就
 *    代表「這個子集合有選 nums[i]」、是 0 就代表「沒選」。所以外層
 *    迴圈跑過 0 到 2^n - 1，就等於窮舉了所有可能的子集合，不用真的
 *    寫遞迴函式。
 * 3. 對每個 mask，內層迴圈檢查每一個 bit 位置：如果 `mask & (1<<i)`
 *    不為 0，代表這個子集合有包含 nums[i]，把它 OR 進 orOp。
 * 4. 算完這個子集合的 OR 值後，跟 target 比較，相等就計數 +1。
 * 5. **跟前一版 DFS 回溯的對應關係**：DFS 版本的「選」跟「不選」兩條
 *    遞迴分支，展開後其實就是在窮舉同樣的 2^N 種組合；這版把「遞迴
 *    呼叫堆疊」換成「用 mask 的每個 bit 直接表示選或不選」，本質上
 *    是同一種暴力枚舉，只是用迭代取代遞迴，寫法更緊湊，但可讀性上
 *    對「選或不選」這個決策過程沒有 DFS 版直觀。
 */
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0, bit_or<int>());
        int n = nums.size();
        int ans = 0;
        for(int mask = 0; mask < (1 << n); mask++) {
            int orOp = 0;
            for(int i = 0; i < nums.size(); i++) {
                if(mask & (1 << i)) {
                    orOp |= nums[i];
                }
            }
            if(orOp == target) ans++;
        }
        return ans;
    }
};