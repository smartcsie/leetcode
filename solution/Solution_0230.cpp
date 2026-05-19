/**
 * 題目：230. Kth Smallest Element in a BST (BST 中第 K 小的元素)
 * 難度：中等 (Medium)
 * 
 * 時間複雜度：O(H + k) - H 為樹高，k 為目標序位。最壞情況需要走遍所有節點。
 * 空間複雜度：O(H) - 遞迴產生的棧空間。
 * 
 * 修正重點：
 * 1. 使用引用傳遞 `int& k`：這樣每一層遞迴對 k 的減量，所有層級都能同步看到。
 * 2. 提早結束：一旦找到結果，就沒必要繼續走右子樹或其他路徑。
 */

class Solution {
public:
    int res = -1;
    void inorder(TreeNode* root, int& k) {
        if(!root || res!= -1) return;
        inorder(root->left, k);
        k--;
        if(k == 0) {
            res = root->val;
            return;
        }
        inorder(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return res;
    }
};
