/**
 * 題目：108. Convert Sorted Array to Binary Search Tree (將有序陣列轉換為二元搜尋樹)
 * 難度：簡單 (Easy)
 * 描述：將一個高度平衡的有序陣列轉換為二元搜尋樹 (BST)。
 * * 時間複雜度：O(N) - 每個節點都會被訪問一次並建立。
 * 空間複雜度：O(log N) - 遞迴堆疊的深度，即樹的高度。
 * * 優化思路：
 * 取中間值作為根節點，保證左子樹與右子樹的節點數差不超過 1，確保高度平衡。
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(x), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0 , nums.size() -1);
    }
private:
    TreeNode* dfs(vector<int>& nums, int left, int right) {
        if(left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = dfs(nums, left, mid - 1);
        root->right = dfs(nums, mid + 1, right);
        return root;
    }
};
