/**
 * 題目：1373. Maximum Sum BST in Binary Tree
 * 難度：困難 (Hard)
 * 描述：給定一棵二元樹，找出其中節點值總和最大的「合法二元搜尋樹（BST）
 * 子樹」，回傳那個子樹的節點值總和（如果沒有任何合法 BST 子樹，回傳 0）。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(H)
 *
 * 解法思路：
 * （Tree DP，由下往上同時驗證「這是不是合法 BST」+ 累計總和，一次
 * 後序遍歷完成，不用對每個節點重新驗證整棵子樹）：
 * 1. 每個節點回傳一個包裝資訊：{是否為合法BST, 子樹最小值, 子樹最大值,
 *    子樹總和}。這是這題的關鍵技巧——如果每次都重新驗證整棵子樹是不是
 *    BST 會變成 O(N²)，用後序遍歷讓每個節點只需要看子節點回傳的資訊，
 *    就能 O(1) 判斷自己這棵子樹合不合法。
 * 2. 空節點視為「合法的空 BST」，min = +∞、max = -∞（這樣任何節點的值
 *    都能滿足 > min、< max 的邊界檢查，不會誤判空子樹擋到判斷）。
 * 3. 狀態轉移：一個節點要組成合法 BST，需要同時滿足——
 *    (a) 左子樹本身合法、右子樹本身合法
 *    (b) 自己的值 > 左子樹的最大值（左邊都要比自己小）
 *    (c) 自己的值 < 右子樹的最小值（右邊都要比自己大）
 *    全部滿足才是合法 BST，這時候更新全域最大總和 maxSum，並往上回傳
 *    {true, 自己這棵子樹的最小值, 最大值, 總和}。
 * 4. 只要有一項不滿足，這個節點本身（連同它的子樹）就不是合法 BST，
 *    往上回傳 {false, ...}，讓父節點知道不能把自己算進去。
 */
class Solution {
    int maxSum = 0;
    struct Info { bool isBST; int minVal; int maxVal; int sum; };

    Info dfs(TreeNode* node) {
        if (!node) return {true, INT_MAX, INT_MIN, 0};
        Info left = dfs(node->left);
        Info right = dfs(node->right);
        if (left.isBST && right.isBST && node->val > left.maxVal && node->val < right.minVal) {
            int sum = left.sum + right.sum + node->val;
            maxSum = max(maxSum, sum);
            int minVal = node->left ? left.minVal : node->val;
            int maxVal = node->right ? right.maxVal : node->val;
            return {true, minVal, maxVal, sum};
        }
        return {false, 0, 0, 0};
    }

public:
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
