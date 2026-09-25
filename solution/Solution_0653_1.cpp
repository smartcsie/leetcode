/*
 * 題目：653. Two Sum IV - Input is a BST
 * 連結：https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
 * 難度：Easy
 * 分類主題：Tree, BST
 * 技巧：雙指針 + BST 中序/反中序疊代器（雙向走訪）
 * 描述：給定 BST 的根節點與整數 k，判斷樹中是否存在兩個節點的值相加等於 k。
 * 時間複雜度：O(N)，每個節點最多被 push/pop 一次
 * 空間複雜度：O(H)，H 為樹高，為疊代器內部 stack 的最大深度
 * 解法思路：
 *   1. 用一個可雙向控制的疊代器 BSTIterator：
 *      - leftToRight = true 時表現為「中序疊代器」，next() 依序吐出遞增的值（由小到大）。
 *      - leftToRight = false 時表現為「反中序疊代器」，next() 依序吐出遞減的值（由大到小）。
 *   2. 建立 left（由小到大）與 right（由大到小）兩個疊代器，模擬雙指針從兩端向中間逼近：
 *      - l 是目前最小值，r 是目前最大值。
 *      - 若 l + r == k，找到答案，回傳 true。
 *      - 若 l + r < k，代表和太小，left 往右移（取下一個較大的值）。
 *      - 若 l + r > k，代表和太大，right 往左移（取下一個較小的值）。
 *      - 當 l >= r（兩指針交會或錯開）時，代表所有組合都檢查過仍無解，回傳 false。
 */
class BSTIterator {
public:
    // leftToRight = true：由小到大走訪（中序）；false：由大到小走訪（反中序）
    BSTIterator(TreeNode* root, bool leftToRight) : leftToRight(leftToRight) {
        pushUntilNull(root);
    }

    // 取出目前最小（或最大）的節點值，並把下一批候選節點推入 stack
    int next() {
        TreeNode* root = stack.top();
        stack.pop();
        // 由小到大時，取出節點後改往它的右子樹展開；由大到小則改往左子樹展開
        pushUntilNull(leftToRight ? root->right : root->left);
        return root->val;
    }

private:
    stack<TreeNode*> stack;   // 修正原本的筆誤 tack -> stack
    bool leftToRight;

    // 沿著指定方向（左或右）一路把節點壓入 stack，直到底（nullptr）為止
    // leftToRight = true 時一路往左壓（之後 next() 吐出的是遞增序列）
    // leftToRight = false 時一路往右壓（之後 next() 吐出的是遞減序列）
    void pushUntilNull(TreeNode* root) {
        while (root != nullptr) {
            stack.push(root);
            root = leftToRight ? root->left : root->right;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator left(root, true);   // 由小到大的疊代器
        BSTIterator right(root, false); // 由大到小的疊代器

        // l：目前最小值；r：目前最大值，雙指針向中間逼近
        for (int l = left.next(), r = right.next(); l < r;) {
            const int sum = l + r;
            if (sum == k) return true;      // 找到一組解
            if (sum < k) l = left.next();   // 和太小，換更大的 l
            else r = right.next();          // 和太大，換更小的 r
        }
        return false; // 所有可能組合都試過仍找不到
    }
};