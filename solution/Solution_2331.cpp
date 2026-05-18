/**
 * 題目：2331. Evaluate Boolean Binary Tree (計算布林二元樹的值)
 * 難度：簡單 (Easy)
 * 描述：給定一棵完整二元樹的根節點 root。
 *      - 葉子節點儲存布林值：0 代表 False，1 代表 True。
 *      - 非葉子節點儲存運算子：2 代表 OR (或)，3 代表 AND (與)。
 *      請計算並回傳該樹最終評估出的布林結果。
 * 
 * 時間複雜度：O(n) - 其中 n 為樹的節點總數，每個節點都會被訪問一次。
 * 空間複雜度：O(h) - 其中 h 為樹的高度，遞迴呼叫時系統棧（stack）的深度。
 * 
 * 解法思路：
 * 1. 採用後序遍歷 (Post-order Traversal) 的思想。
 * 2. 終止條件（葉子節點）：當遇到沒有子節點的節點時，直接回傳其數值（0 或 1）。
 * 3. 遞迴步驟：
 *    - 先評估左子樹的結果。
 *    - 再評估右子樹的結果。
 * 4. 根據當前節點的 val (2 或 3) 結合左右子樹的布林值進行運算並回傳。
 */


class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(!root->left && !root->right) return root->val;
        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);
        if(root->val == 2) return  left || right;
        else return  left && right;
    }
};
