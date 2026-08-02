/**
 * 題目：590. N-ary Tree Postorder Traversal
 * 難度：Easy
 * 描述：給定一棵 N 叉樹，回傳其節點值的後序走訪結果。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * DFS 遞迴走訪，先依序遞迴走訪每個子節點（children 是陣列），全部子節點處理完後，
 * 才把目前節點值加進結果（跟前序的差別只在於 push_back 的時機從最前面移到最後面）。
 * 遞迴堆疊深度最壞情況（鏈狀樹）為 O(N)。
 */
class Solution {
private:
    void postorder(Node* root, vector<int>& ans) {
        if(!root) return;

        for(Node* child : root->children) {
            postorder(child, ans);
        }
        ans.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
};