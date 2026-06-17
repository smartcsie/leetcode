/**
 * 題目：988. Smallest String Starting From Leaf (從葉節點開始的最小字串)
 * 難度：中等 (Medium)
 * 描述：找出從葉節點到根節點路徑字典序最小的字串。
 * * 時間複雜度：O(N) - 每個節點訪問一次，N 為節點總數。
 * 空間複雜度：O(H) - H 為樹的高度 (遞迴堆疊深度)。
 * * 優化思路：
 * 1. 回溯法：透過 push_back/pop_back 在單一 string 上操作，將空間開銷降至最低。
 * 2. 減少記憶體分配：使用 path.reserve() 避免 string 在遍歷過程中的動態擴容。
 */

class Solution {
void dfs(TreeNode* root, string& cur, string& smallest) {
    if(!root) return;
    cur.push_back(root->val + 'a');
    if(!root->left && !root->right) {
        string temp = cur;
        reverse(temp.begin(), temp.end());
        if(smallest == "" || temp < smallest) {
            smallest = temp;
        }
    } else {
        if(root->left) dfs(root->left, cur, smallest);
        if(root->right)  dfs(root->right, cur, smallest);
    }
    cur.pop_back();
}
public:
    string smallestFromLeaf(TreeNode* root) {
        string smallest = "";
        string cur = "";
        dfs(root, cur, smallest);
        return smallest;
    }
};
