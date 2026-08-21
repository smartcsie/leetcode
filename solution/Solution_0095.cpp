/**
 * 題目：95. Unique Binary Search Trees II
 * 難度：中等 (Medium)
 * 描述：給定一個整數 n，產生所有由 1 到 n 組成、結構不同的二元搜尋樹，
 * 回傳這些樹的根節點清單。
 *
 * 時間複雜度：O(Catalan(N) * N)，Catalan(N) 是結果樹的總數
 * 空間複雜度：O(Catalan(N) * N)
 *
 * 解法思路：
 * （Interval DP + 記憶化，build(start, end) 代表「用 start~end 這段
 * 數字」能組成的所有 BST 清單）：
 * 1. 這題本質上跟其他 Interval DP 題目一樣，子問題是「某個連續數字區間
 *    能怎麼組成結構」，只是這裡回傳的不是一個最佳值，而是「所有可能的
 *    樹」這個集合。
 * 2. 狀態轉移：枚舉區間 [start, end] 裡每個數字 rootVal 當作根節點，
 *    左子樹要用 [start, rootVal-1] 組成、右子樹要用 [rootVal+1, end]
 *    組成（BST 性質：左子樹全部小於根、右子樹全部大於根）。
 * 3. 遞迴取得左子樹的所有可能清單 lefts、右子樹的所有可能清單 rights，
 *    兩兩配對（笛卡兒積）組成新的根節點為 rootVal 的樹，全部收集進
 *    result。
 * 4. 用 map<(start,end), vector<TreeNode*>> 做記憶化：因為不同的
 *    rootVal 選擇，可能會重複用到同樣的 (start, end) 子區間（例如
 *    n=4 時，[1,2] 這個子區間在算 rootVal=3 跟 rootVal=4 時都會用到），
 *    記憶化避免重複建構同一批子樹。
 * 5. base case：start > end 時代表空子樹，回傳 {nullptr} 這個「只包含
 *    一個空指標」的清單（讓外層笛卡兒積能正確運作）。
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        map<pair<int,int>, vector<TreeNode*>> memo;
        return build(1, n, memo);
    }

private:
    vector<TreeNode*> build(int start, int end, map<pair<int,int>, vector<TreeNode*>>& memo) {
        if (start > end) return { nullptr };
        auto key = make_pair(start, end);
        if (memo.count(key)) return memo[key];

        vector<TreeNode*> result;
        for (int rootVal = start; rootVal <= end; ++rootVal) {
            vector<TreeNode*> lefts = build(start, rootVal - 1, memo);
            vector<TreeNode*> rights = build(rootVal + 1, end, memo);
            for (TreeNode* l : lefts) {
                for (TreeNode* r : rights) {
                    TreeNode* root = new TreeNode(rootVal);
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
            }
        }
        memo[key] = result;
        return result;
    }
};
