/*
 * 題目：700. Search in a Binary Search Tree
 * 難度：Easy
 * 描述：給定二元搜尋樹的根節點 root 與整數 val，找出節點值等於 val 的節點，回傳以該節點為根的子樹；若不存在，回傳 null。
 * 分類主題：binary-search-tree
 * 技巧：利用 BST 性質剪枝, 遞迴搜尋
 * 時間複雜度：O(h)，h 為樹高（平衡時 O(log n)，退化成鏈時 O(n)）
 * 空間複雜度：O(h)（遞迴呼叫堆疊；改成迴圈可降到 O(1)）
 * 解法思路：
 *   1. BST 的性質：左子樹所有值小於根，右子樹所有值大於根，每一步只需要走其中一邊
 *   2. 節點為空：表示沒找到，回傳 nullptr
 *   3. 節點值等於 val：找到了，回傳該節點（即子樹的根）
 *   4. 節點值小於 val：目標只可能在右子樹，往右找
 *   5. 節點值大於 val：目標只可能在左子樹，往左找
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return nullptr;                              // 走到空節點：不存在
        if(root->val == val) return root;                      // 找到：回傳這個節點
        else if(root->val < val) return searchBST(root->right, val);  // 目標比較大：只找右子樹
        else return searchBST(root->left, val);                       // 目標比較小：只找左子樹
    }
};