/**
 * 題目：538. Convert BST to Greater Tree (把二元搜尋樹轉換為累加樹)
 * 難度：中等 (Medium)
 * 描述：將 BST 每個節點的值，替換為原節點值加上大於該節點的所有節點值之和。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)
 *
 * 解法思路：
 * 1. 反向中序遍歷：先處理右子樹（大的值），累加後處理中間，最後處理左子樹。
 * 2. 狀態維護：利用成員變數 `currentSum` 累加已訪問過的所有節點值。
 */

class Solution {
private:
    int sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return nullptr;
        convertBST(root->right);
        root->val += sum;
        sum = root->val;
        convertBST(root->left);
        return root;
    }
};
