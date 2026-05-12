


/**
 * 解題思路：雙重遞迴 (Recursive DFS)
 * 1. 本題核心：判斷 subRoot 是否為 root 的子樹。
 * 2. 邏輯拆解：
 *    - 主函數 (isSubtree)：負責遍歷 root 的每一個節點。
 *    - 輔助函數 (isSameTree)：負責判斷兩棵樹是否完全相同。
 * 3. 對於 root 的每一個節點，我們都去問：「以這個點為根的子樹，是否跟 subRoot 一模一樣？」
 *    - 如果是，回傳 true。
 *    - 如果不是，則繼續去 root 的左子樹與右子樹中尋找。
 * 
 * Time Complexity: O(m * n) - 其中 m, n 分別為兩棵樹的節點數。最壞情況下需比對每個節點。
 * Space Complexity: O(h) - h 為樹的高度，遞迴呼叫堆疊的深度。
 */

class Solution {
public:
    bool isSametree(TreeNode* p, TreeNode* q) {
        if(p == q) return true;
        if(!p || !q || p->val != q->val) return false;
        return isSametree(p->left, q->left) && isSametree(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(isSametree(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        
    }
};
