/**
 * 題目：951. Flip Equivalent Binary Trees (翻轉等價二元樹)
 * 難度：中等 (Medium)
 * 描述：定義對二元樹進行「翻轉操作」為選擇任一節點，交換其左右子樹。
 *       給定兩棵二元樹 root1、root2，判斷是否能透過任意次數的翻轉操作，
 *       讓 root1 變得與 root2 相同。
 *
 * 時間複雜度：O(min(N1, N2)
 *             最壞情況下需要走訪較小那棵樹的所有節點。
 * 空間複雜度：O(min(N1, N2)
 *
 * 解法思路：
 * 1. 遞迴終止條件：兩者皆空 (Both Null Base Case)：
 *    - 若兩個節點都是 nullptr，代表這個分支完全對應成功，回傳 true。
 * 2. 遞迴終止條件：結構或數值不符 (Mismatch Base Case)：
 *    - 若其中一個為 nullptr（另一個不是），或兩者的節點值不同，
 *      代表這兩棵子樹不可能透過翻轉變得相同，直接回傳 false。
 * 3. 兩種可能的對應方式：不翻轉 或 翻轉 (Two Possible Matchings)：
 *    - 不翻轉：root1 的左子樹對應 root2 的左子樹、右子樹對應右子樹。
 *    - 翻轉：root1 的左子樹對應 root2 的右子樹、右子樹對應左子樹
 *      （因為翻轉操作可以在任意節點進行，所以每個節點都要嘗試這兩種可能）。
 * 4. 只要其中一種對應方式兩邊都遞迴成立即可：
 *    - 用 || 連接兩種情況，只要任一種對應方式能讓左右子樹都遞迴驗證成功，
 *      就代表以目前節點為根的這兩棵子樹是翻轉等價的。
 */
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return  true;
        if(!root1 || !root2 || root1->val != root2->val) return  false;
        return ((flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
                (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left))
                );
    }
};
