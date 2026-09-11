
/**
 * 題目：530. Minimum Absolute Difference in BST (二元搜尋樹的最小絕對差)
 * 難度：簡單 (Easy)
 * 描述：給你一棵二元搜尋樹 (BST) 的根節點 root，返回樹中任意兩個不同節點值之間的最小絕對差。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)
 *
 * 解法思路：
 * 1. BST 特性：中序遍歷 (左 -> 根 -> 右) 的結果是一個「升序」序列。
 * 2. 最小絕對差一定發生在中序遍歷中「相鄰」兩個節點之間。
 * 3. 實作技巧：
 * - 使用一個全域或傳址變數 prev 記錄遍歷過程中的「上一個節點」。
 * - 每次訪問當前節點時，計算 (curr->val - prev->val)，並更新全域最小值 res。
 */

class Solution {
private:
    void inorder(TreeNode* root, int& pre, int& mn) {
        if(!root) return;
        inorder(root->left, pre, mn);
        if(pre != -1) mn = min(mn, root->val - pre);
        pre = root->val;
        inorder(root->right, pre, mn);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int mn = INT_MAX, pre = -1;
        inorder(root, pre, mn);
        return mn;
    }
};