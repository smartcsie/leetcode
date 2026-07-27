/**
 * 題目：889. Construct Binary Tree from Preorder and Postorder Traversal
 * 難度：中等 (Medium)
 * 描述：根據前序與後序遍歷結果還原二元樹（結果可能不唯一，任意合法樹皆可）。
 * * 時間複雜度：O(N) - 每個節點訪問一次。
 * 空間複雜度：O(N) - 雜湊表與遞迴堆疊。
 * * 優化思路：
 * 1. 雜湊預分配：使用 reserve 提升雜湊表效能。
 * 2. 邊界校驗：優化遞迴終止條件，提高代碼穩健性。
 */

class Solution {
private:
    unordered_map<int, int> postorderMap;

    TreeNode* buildSubtree(const vector<int>& preorder, const vector<int>& postorder,
                           int preStart, int postStart, int subSize) {
        // 基本邊界條件
        if (subSize <= 0) return nullptr;
        
        // 建立當前子樹根節點
        TreeNode* root = new TreeNode(preorder[preStart]);
        if (subSize == 1) return root;

        // 前序遍歷中根節點的下一個元素即為「左子樹的根」
        int leftRootVal = preorder[preStart + 1];
        int leftRootIdxInPost = postorderMap[leftRootVal];
        
        // 計算左子樹大小
        int leftSize = leftRootIdxInPost - postStart + 1;
        
        // 遞迴建構
        root->left = buildSubtree(preorder, postorder, 
                                  preStart + 1, postStart, leftSize);
        
        root->right = buildSubtree(preorder, postorder, 
                                   preStart + leftSize + 1, postStart + leftSize, 
                                   subSize - leftSize - 1);
        
        return root;
    }

public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = static_cast<int>(postorder.size());
        postorderMap.reserve(n);
        for (int i = 0; i < n; ++i) {
            postorderMap[postorder[i]] = i;
        }
        return buildSubtree(preorder, postorder, 0, 0, n);
    }
};
