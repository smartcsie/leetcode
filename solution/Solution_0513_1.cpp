// 題目：513. Find Bottom Left Tree Value
// 難度：Medium
// 時間複雜度：O(n)
// 空間複雜度：O(h)，h = 樹高（遞迴堆疊；最壞退化成鏈時為 O(n)）
// 分類主題：tree / binary-tree
// 技巧：DFS 前序（先左後右）+ 深度記錄；只在「更深一層」時更新答案，所以每層只有最左節點會被記下

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int maxDepth = -1;   // 目前見過的最深深度（-1 表示還沒走到任何節點）
        int ans = 0;         // 最深那一層最左邊的值
        dfs(root, 0, maxDepth, ans);   // 根節點的深度是 0
        return ans;                    // 題目保證樹至少有一個節點
    }

private:
    // maxDepth、ans 用參考傳遞，讓整個遞迴過程共用同一份狀態
    void dfs(TreeNode* node, int depth, int& maxDepth, int& ans) {
        if(!node) return;

        // 第一次走到更深的一層：
        // 因為先走左子樹，同一層裡最先被走到的節點一定是最左邊的那個，
        // 所以這個節點就是該層的最左節點。
        // 一定要用 > 而不是 >=，否則同一層後面走到的右邊節點會覆蓋掉左邊的答案
        if(depth > maxDepth) {
            maxDepth = depth;
            ans = node->val;
        }

        dfs(node->left, depth + 1, maxDepth, ans);    // 一定要先左
        dfs(node->right, depth + 1, maxDepth, ans);   // 再右
    }
};