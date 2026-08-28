/**
 * 題目：1026. Maximum Difference Between Node and Ancestor (節點與其祖先之間的最大差值)
 * 難度：中等 (Medium)
 * 描述：給定一棵二元樹的根節點 root，找出樹中任意節點 a 與其祖先節點 b 之間，
 *       |a.val - b.val| 的最大值（a 必須是 b 的子孫節點）。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)
 *
 * 解法思路：
 * 1. 攜帶路徑上的極值往下遞迴 (Carry Min/Max Down the Path)：
 *    - dfs 額外攜帶 minVal 與 maxVal，代表從根節點到目前節點路徑上，所有祖先（含自己之前）的最小值與最大值。
 * 2. 在每個節點更新答案：
 *    - 由於最大差值必定發生在「路徑上的極值」與「目前節點」之間，
 *      每次進入節點時，先用 |minVal - root->val| 與 |maxVal - root->val| 更新全域最大差值 maxDiff。
 * 3. 更新極值後繼續往下傳遞：
 *    - 把目前節點的值也納入考量，更新 minVal 與 maxVal，再繼續遞迴左右子樹，
 *      確保子孫節點能拿到「包含目前節點」的最新極值範圍。
 * 4. 初始化：
 *    - 從根節點開始遞迴時，minVal 與 maxVal 都先設為 root->val 本身，作為路徑的起點。
 */
class Solution {
private:
    void dfs(TreeNode* root, int mn, int mx, int& maxDiff) {
        if(!root) return;
        mn = min(mn, root->val);
        mx = max(mx, root->val);
        maxDiff = max(maxDiff, mx - mn);
        dfs(root->left, mn, mx, maxDiff);
        dfs(root->right, mn, mx, maxDiff);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        dfs(root, INT_MAX, INT_MIN, ans);
        return ans;
    }
};
