/**
 * 題目：106. Construct Binary Tree from Inorder and Postorder Traversal
 * 難度：中等 (Medium)
 * 描述：根據中序與後序遍歷結果還原二元樹。
 * * 時間複雜度：O(N) - 每個節點建立一次，雜湊表查詢為 O(1)。
 * 空間複雜度：O(N) - 雜湊表與遞迴堆疊深度。
 * * 優化思路：
 * 1. 雜湊預分配：使用 reserve 避免雜湊表擴容開銷。
 * 2. 參數安全性：使用 const 引用避免傳遞時的 vector 拷貝。
 */

class Solution {
private:
    unordered_map<int, int> inorderMap;

    TreeNode* buildSubtree(const vector<int>& inorder, const vector<int>& postorder, 
                           int inStart, int postStart, int subSize) {
        if (subSize <= 0) return nullptr;

        // 1. 後序遍歷的最後一個元素必定是當前子樹的根節點
        int rootVal = postorder[postStart + subSize - 1];
        int rootIdx = inorderMap[rootVal];
        
        // 2. 計算左子樹大小
        int leftSize = rootIdx - inStart;
        
        TreeNode* root = new TreeNode(rootVal);
        
        // 3. 遞迴建構左子樹與右子樹
        // 左子樹：中序起點不變，後序起點不變
        root->left = buildSubtree(inorder, postorder, 
                                  inStart, postStart, leftSize);
                                  
        // 右子樹：中序起點跳過根節點，後序起點跳過左子樹部分
        root->right = buildSubtree(inorder, postorder, 
                                   rootIdx + 1, postStart + leftSize, 
                                   subSize - leftSize - 1);
                                   
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 預分配雜湊表空間，提升效能
        inorderMap.reserve(inorder.size());
        for (int i = 0; i < (int)inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }
        
        return buildSubtree(inorder, postorder, 0, 0, (int)inorder.size());
    }
};
