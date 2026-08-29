/**
 * 題目：90. Subsets II
 * 難度：中等 (Medium)
 * 分類主題：bit-bitmask-subset-enumeration
 * 描述：給定一個「可能包含重複元素」的整數陣列 nums，求所有不重複的
 * 子集合（不能有兩個內容相同的子集合出現在結果裡）。
 *
 * 時間複雜度：O(N * 2^N)
 * 空間複雜度：O(N * 2^N)（存放所有子集合的輸出）
 *
 * 解法思路：
 * （Bitmask 窮舉，跟 78 Subsets 幾乎一模一樣，多的是「怎麼跳過會
 * 產生重複內容的 mask」這個額外判斷，是這題真正的難點）：
 * 1. 先排序陣列，讓相同的數字都排在相鄰位置——這是後面判斷重複的
 *    前提，一定要先做。
 * 2. 一樣用 mask 從 0 到 2^n-1 窮舉所有子集合的「選或不選」組合。
 * 3. **關鍵的去重判斷**：如果 `nums[i] == nums[i-1]`（相鄰兩個數字
 *    相同），但這個 mask 「沒選 nums[i-1]、卻選了 nums[i]」，這個
 *    mask 直接跳過不處理。
 *    - **為什麼這樣能去重**：假設有兩個相同的數字在位置 i-1、i，
 *      如果某個 mask 選了 nums[i] 但沒選 nums[i-1]，組出來的子集合
 *      內容，會跟「選 nums[i-1] 但沒選 nums[i]」的另一個 mask 組出
 *      來的內容完全一樣（因為兩個數字本身相等，選誰在「子集合內容」
 *      上沒有差別）。與其事後判斷「這個子集合是不是已經出現過」
 *      （需要額外的雜湊集合來查重，多一層空間跟時間開銷），不如直接
 *      規定「一定要照順序、從前面的重複元素開始選」，只保留
 *      「選了 nums[i] 就一定也選了 nums[i-1]」的 mask，另一種選法
 *      直接跳過，這樣天生就不會產生重複。
 * 4. 通過檢查的 mask，才依照 bit 位置組出實際的子集合內容，加進
 *    結果。
 * 5. 這個「跳過會重複的 mask」的技巧，本質上跟回溯版解法裡常見的
 *    `if (i > start && nums[i] == nums[i-1]) continue;` 去重邏輯是
 *    同一個道理，只是回溯版是在遞迴的當下跳過分支，這裡是在窮舉
 *    mask 的當下跳過整個 mask。
 */

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int mask = 0; mask < (1 << n); mask++) {
            bool skip = false;
            for (int i = 1; i < n; i++) {
                if (nums[i] == nums[i - 1] &&
                    !(mask & (1 << (i - 1))) && (mask & (1 << i))) {
                    skip = true;
                    break;
                }
            }
            if (skip) continue;
            vector<int> subset;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) subset.push_back(nums[i]);
            }
            ans.push_back(subset);
        }
        return ans;
    }
};