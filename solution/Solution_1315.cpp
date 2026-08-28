/**
 * 題目：1315. Sum of Nodes with Even-Valued Grandparent (祖父節點值為偶數的節點總和)
 * 難度：中等 (Medium)
 * 描述：給定二元樹的根節點 root，如果一個節點的祖父節點（grandparent，即父節點的父節點）
 *       值為偶數，則稱這個節點為「好節點」。請回傳所有好節點的值之總和，若不存在祖父節點則不計入。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)
 *
 * 解法思路：
 * 1. 攜帶父節點與祖父節點往下遞迴 (Carry Parent & Grandparent Down)：
 *    - dfs 額外攜帶 parent（目前節點的父節點）與 grandpa（目前節點的祖父節點），
 *      讓每個節點都能直接得知自己的祖父節點是誰。
 * 2. 判斷並累加答案：
 *    - 進入節點後，先檢查 grandpa 是否存在且其值為偶數，若成立則把目前節點的值加進 ans。
 * 3. 遞迴時正確傳遞新的親屬關係：
 *    - 對左右子節點遞迴時，子節點的新父節點是目前節點 root，
 *      子節點的新祖父節點則是目前節點的父節點 parent（也就是呼叫時傳入的 dfs(child, root, parent, ans)）。
 *    - 這樣每往下一層，親屬關係就會正確地整體往下平移一層。
 */
class Solution {
private:
    void dfs(TreeNode* root, int parent, int grandpa, int& sum) {
        if(!root) return;
        if(grandpa!= -1 && (grandpa % 2) == 0) sum += root->val;
        dfs(root->left, root->val , parent, sum);
        dfs(root->right, root->val, parent, sum);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        dfs(root, -1, -1, sum);
        return sum;
    }
};
