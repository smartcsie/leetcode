/**
 * 題目：78. Subsets
 * 難度：Medium
 * 描述：給定元素互不相同的整數陣列 nums，回傳所有可能的子集（冪集），
 *       解集不能包含重複的子集，順序不拘。
 *
 * 分類主題：backtracking-combination
 * 技巧：迭代式逐步擴展子集, 每處理一個數字子集數量翻倍, reserve 預先配置空間
 *
 * 時間複雜度：O(n * 2^n)
 * 空間複雜度：O(1)（不計輸出，沒有遞迴也沒有暫存陣列）
 *
 * 解法思路：迭代擴展
 * 1. 一開始 ans 只有空集合。
 * 2. 每處理一個數字 x，就把「目前所有子集」各複製一份並在尾端加上 x，
 *    新子集接在 ans 後面，子集數量剛好翻倍。
 * 3. 先固定 size = ans.size() 再迴圈，本輪新增的子集不會在同一輪被再次擴展。
 * 4. 處理完 n 個數字，共 2^n 個子集。
 * 5. 先 reserve(1 << n)，避免 push_back 過程中反覆搬移整個答案。
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}};  // 一開始只有空集合
        ans.reserve(1 << nums.size());

        for (int x : nums) {
            int size = ans.size();  // 本輪開始前的子集數量
            for (int j = 0; j < size; j++) {
                ans.push_back(ans[j]);  // 複製現有子集
                ans.back().push_back(x);  // 再加上 x，形成新子集
            }
        }
        return ans;
    }
};