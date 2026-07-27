/**
 * 題目：105. Construct Binary Tree from Preorder and Inorder Traversal
 * 難度：中等 (Medium)
 * 描述：根據前序與中序遍歷結果還原二元樹。
 * * 時間複雜度：O(N) - 每個節點建立一次，雜湊表查詢為 O(1)。
 * 空間複雜度：O(N) - 雜湊表與遞迴堆疊深度。
 * * 優化思路：
 * 1. 雜湊預分配：使用 reserve 避免雜湊表擴容開銷。
 * 2. 參數優化：使用 const 引用避免傳遞時的 vector 拷貝。
 */

class Solution {
private:
    unordered_map<int, int> inorderMap;

    TreeNode* buildSubtree(const vector<int>& preorder, const vector<int>& inorder,  
                           int preStart, int inStart, int subSize) {
        if (subSize <= 0) return nullptr;

        // 1. 前序遍歷的第一個元素為根節點
        int rootVal = preorder[preStart];
        int rootIdx = inorderMap[rootVal];
        
        // 2. 計算左子樹大小
        int leftSize = rootIdx - inStart;
        
        TreeNode* root = new TreeNode(rootVal);
        
        // 3. 遞迴建構子樹
        root->left = buildSubtree(preorder, inorder, preStart + 1, inStart, leftSize);
        root->right = buildSubtree(preorder, inorder, preStart + leftSize + 1, rootIdx + 1, subSize - leftSize - 1);
        
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 預分配雜湊表空間，提升效能
        inorderMap.reserve(inorder.size());
        for (int i = 0; i < (int)inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }
        return buildSubtree(preorder, inorder, 0, 0, (int)inorder.size());
    }
};
