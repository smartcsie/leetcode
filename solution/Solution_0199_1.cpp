/*
 * 題目：199. Binary Tree Right Side View
 * 難度：Medium
 * 描述：給定二元樹的根節點 root，想像自己站在樹的右側，回傳從上到下所能看到的節點值。
 * 分類主題：tree-dfs-global
 * 技巧：DFS 先右後左, 用深度判斷該層是否已記錄, res.size() 兼作已處理層數
 * 時間複雜度：O(n)
 * 空間複雜度：O(h)（遞迴堆疊，h 為樹高，不含輸出）
 * 解法思路：
 *   1. 從右邊看到的，就是每一層最右邊的那個節點
 *   2. 用 DFS 走訪，傳入目前深度 depth，並且「先走右子樹，再走左子樹」
 *   3. 每一層第一個被走到的節點一定是該層最右邊的節點
 *   4. 判斷方式：res.size() 等於已經記錄的層數，若 depth == res.size()，表示這一層還沒有記錄過，這個節點就是最右節點，放入結果
 *   5. 其餘節點（該層已有記錄）直接略過，但仍要往下走，因為它的子節點可能是更深層的最右節點（例如右子樹較淺時，要由左子樹補上）
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }

private:
    void dfs(TreeNode* node, int depth, vector<int>& res) {
        if (!node) return;
        if (depth == (int)res.size()) {      // 這一層第一次被走到 → 最右邊的節點
            res.push_back(node->val);
        }
        dfs(node->right, depth + 1, res);    // 先右
        dfs(node->left, depth + 1, res);     // 後左
    }

};