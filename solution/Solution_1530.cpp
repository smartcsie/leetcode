/**
 * 題目：1530. Number of Good Leaf Nodes Pairs (好葉子節點對的數量)
 * 難度：中等 (Medium)
 * 描述：給定二元樹 root 與整數 distance，若兩個葉子節點之間的最短路徑長度（邊數）
 *       小於等於 distance，則稱這兩個葉子節點形成一組「好葉子節點對」。
 *       請回傳樹中好葉子節點對的總數。
 *
 * 時間複雜度：O(N×D²) - N 為節點數，D 為 distance；每個節點在合併左右子樹結果時，
 *             需要用雙層迴圈比對長度分佈（最多 D × D 次），故整體約為 O(N × D²)。
 * 空間複雜度：O(H×D) - 遞迴呼叫堆疊深度為樹高 H，每層額外配置大小為 (distance+1) 的向量。
 *
 * 解法思路：
 * 1. 後序遍歷回傳「葉子距離分佈」(Post-order + Distance Distribution)：
 *    - dfs 對每個節點回傳一個長度為 (distance+1) 的向量，
 *      其中 index i 代表「以目前節點為根的子樹中，距離目前節點為 i 的葉子節點數量」。
 * 2. 葉子節點的基本情況：
 *    - 若目前節點是葉子節點，回傳的向量中只有 index 1 為 1（代表自己就是距離為 1 的葉子），其餘為 0。
 * 3. 合併左右子樹並統計好節點對：
 *    - 取得左子樹分佈 l 與右子樹分佈 r 後，透過雙層迴圈檢查所有 (i, j) 組合，
 *      若 i + j <= distance 且 l[i]、r[j] 皆有葉子節點，代表這些葉子兩兩配對後路徑長度合法，
 *      將 l[i] * r[j] 累加進全域答案 res（因為經過目前節點的路徑長度恰為 i + j）。
 * 4. 更新並回傳目前子樹的葉子距離分佈：
 *    - 把左右子樹的葉子距離統一往上平移一層（i + 1），合併成目前節點的分佈往上回傳，
 *      供上層節點繼續進行配對統計；若距離已達到 distance 上限則不再繼續累加（避免無意義的無效距離）。
 */
class Solution {
private:
    int res;
    vector<int> dfs(TreeNode* root, int distance) {
        if (!root) return vector<int>(distance + 1, 0);  // ✅ 回傳全 0 vector
        if (!root->left && !root->right) {
            vector<int> leaf(distance + 1, 0);
            leaf[1] = 1;
            return leaf;
        }

        auto l = dfs(root->left, distance);
        auto r = dfs(root->right, distance);
        vector<int> ans(distance + 1, 0);

        for (int i = 1; i <= distance; i++) {
            for (int j = 1; j <= distance; j++) {
                if (i + j <= distance && l[i] && r[j]) {
                    res += l[i] * r[j];
                }
            }
        }

        for (int i = 1; i < distance; i++) {
            if (l[i]) ans[i + 1] += l[i];
            if (r[i]) ans[i + 1] += r[i];
        }

        return ans;
    }

public:
    int countPairs(TreeNode* root, int distance) {
        res = 0;
        dfs(root, distance);
        return res;
    }
};
