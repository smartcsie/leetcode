/**
 * 題目：617. Merge Two Binary Trees (合併二元樹)
 * 難度：簡單 (Easy)
 * 描述：將兩棵樹合併，重疊節點數值相加，不重疊的節點則直接作為合併後的節點。
 * * 時間複雜度：O(min(N, M)) - N 和 M 分別為兩棵樹的節點數，只需遍歷重疊部分。
 * 空間複雜度：O(min(H1, H2)) - 遞迴堆疊深度由較淺的樹高度決定。
 * * 優化思路：
 * 採用原地修改策略 (In-place)，直接將 root2 的數值與子節點合併至 root1 中，
 * 避免了額外配置新節點記憶體，是空間複雜度最低的做法。
 */

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // 若 root1 為空，合併結果就是 root2
        if (!root1) return root2;
        // 若 root2 為空，合併結果就是 root1
        if (!root2) return root1;
        
        // 處理節點數值：將 root2 的值累加到 root1
        root1->val += root2->val;
        
        // 遞迴合併左子樹與右子樹
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        
        return root1;
    }
};
