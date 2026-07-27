/**
 * 題目：2476. Closest Nodes Queries in a Binary Search Tree
 * 難度：中等 (Medium)
 * 描述：在 BST 中針對每個查詢找出小於等於該數的最大值 (min) 與大於等於該數的最小值 (max)。
 * * 時間複雜度：O(N + Q log N) - N 為節點數，Q 為查詢數。
 * 空間複雜度：O(N) - 用於儲存有序陣列。
 * * 優化思路：
 * 1. 展平 (Flattening)：中序遍歷得到遞增陣列。
 * 2. 二分搜尋 (Binary Search)：使用 STL 內建函數進行高效查詢。
 */

class Solution {
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> nums;
        inorder(root, nums);
        vector<vector<int>> ans;
        ans.reserve(queries.size()); // 預分配記憶體
        for (int q : queries) {
            // mi: 小於等於 q 的最大值 (upper_bound - 1)
            // mx: 大於等於 q 的最小值 (lower_bound)
            auto it_mx = lower_bound(nums.begin(), nums.end(), q);
            int mi = -1, mx = -1;
            // 處理最大值 (mx)
            if (it_mx != nums.end()) mx = *it_mx;
            // 處理最小值 (mi)
            // 如果 it_mx 指向第一個大於等於 q 的元素，則該元素前一個即為小於 q 的元素
            // 如果 it_mx 是 begin，代表沒有小於 q 的元素
            if (it_mx != nums.begin()) {
                // 如果找到的元素剛好等於 q，則 mi 就是 q
                if (it_mx != nums.end() && *it_mx == q) mi = *it_mx;
                else mi = *prev(it_mx);
            } else if (it_mx != nums.end() && *it_mx == q) {
                mi = *it_mx;
            }
            ans.push_back({mi, mx});
        }
        return ans;
    }
private:
    void inorder(TreeNode* root, vector<int>& nums) {
        if (!root) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
};
