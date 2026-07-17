/**
 * 題目：1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
 * 描述：在兩棵結構完全相同的樹中，找到原樹 target 節點在複製樹中的對應位置。
 * 
 * 解法思路：
 * 1. 同步遍歷兩棵樹 (original 與 cloned)。
 * 2. 遞迴終止條件：若 original 為空則返回 nullptr；若找到 target 則返回 cloned 當前節點。
 * 3. 利用遞迴回傳機制：若左子樹找到結果則直接回傳，否則返回右子樹的搜尋結果。
 */



class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        // 1. 基本終止條件
        if (!original) return nullptr;
        
        // 2. 找到目標：原樹與 target 指標相等時，即為解答
        if (original == target) return cloned;
        
        // 3. 遞迴遍歷：同時走訪兩棵樹的左子樹與右子樹
        TreeNode* left = getTargetCopy(original->left, cloned->left, target);
        if (left) return left; // 若左側已找到則提前返回
        
        return getTargetCopy(original->right, cloned->right, target);
    }
};
