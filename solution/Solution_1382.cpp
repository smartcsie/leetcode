/**
 * 題目：1382. Balance a Binary Search Tree (平衡二元搜尋樹)
 * 難度：中等 (Medium)
 * 描述：將一棵二元搜尋樹轉換為高度平衡的 BST。
 * * 時間複雜度：O(N) - 遍歷節點與重建樹皆為線性。
 * 空間複雜度：O(N) - 用於儲存節點值的陣列。
 * * 優化思路：
 * 1. 中序遍歷：取得 BST 的有序數值。
 * 2. 分治建樹：每次取陣列中點作為根節點，左右兩側分別建構子樹，確保平衡。
 */

class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sortedNums;
        inorder(root, sortedNums);
        return buildBalancedBST(sortedNums, 0, sortedNums.size() - 1);
    }

private:
    // 將樹轉為有序陣列
    void inorder(TreeNode* root, vector<int>& nums) {
        if (!root) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    // 利用有序陣列重建平衡樹 (遞迴分治)
    TreeNode* buildBalancedBST(const vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        
        node->left = buildBalancedBST(nums, left, mid - 1);
        node->right = buildBalancedBST(nums, mid + 1, right);
        
        return node;
    }
};
