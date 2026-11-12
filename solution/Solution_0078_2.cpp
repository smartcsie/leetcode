/**
 * 題目：78. Subsets
 * 難度：Medium
 * 描述：給定元素互不相同的整數陣列 nums，回傳所有可能的子集（冪集），
 *       解集不能包含重複的子集，順序不拘。
 *
 * 分類主題：bit-bitmask-subset-enumeration
 * 技巧：位元遮罩列舉所有子集, mask 的第 i 位元代表是否選 nums[i], 直接用整數位元運算
 *
 * 時間複雜度：O(n * 2^n)
 * 空間複雜度：O(n)，暫存的一個子集（不計輸出）
 *
 * 解法思路：位元遮罩
 * 1. n 個元素共有 2^n 種選法，用整數 mask 的第 i 位元表示「是否選 nums[i]」。
 * 2. mask 從 0 跑到 2^n - 1，剛好列舉所有選法，每個 mask 對應一個子集。
 * 3. 對每個 mask 掃過 n 個位元，位元為 1 就把 nums[i] 放進子集。
 * 4. 直接用 mask >> i & 1 判斷位元，比先轉成字串再逐字元比對快很多，
 *    1 << n 也比 pow(2, n) 好（pow 是浮點運算）。
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        ans.reserve(1 << n);

        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> v;
            for (int i = 0; i < n; i++) {
                if (mask >> i & 1) v.push_back(nums[i]);  // 第 i 位元為 1：選 nums[i]
            }
            ans.push_back(v);
        }
        return ans;
    }
};