/**
 * 題目：965. Univalued Binary Tree (單值二元樹)
 * 難度：簡單 (Easy)
 * 描述：檢查二元樹中每個節點的值是否皆與根節點相同。
 * * 時間複雜度：O(N) - 每個節點至多訪問一次。
 * 空間複雜度：O(H) - 遞迴堆疊的深度，H 為樹的高度。
 * * 優化思路：
 * 1. 若根節點為空，直接回傳 true。
 * 2. 獲取根節點的值作為基準值。
 * 3. 遞迴檢查每個節點是否等於基準值，若發現任一節點不符，立即回傳 false。
 */

class Solution {
private:
    bool isUnivalTree(TreeNode* root, int value) {
        if(!root) return true;
        return  root->val == value &&
                isUnivalTree(root->left, value) &&
                isUnivalTree(root->right, value) ;
    }
public:
    bool isUnivalTree(TreeNode* root) {
        return isUnivalTree(root, root->val);
    }
};
