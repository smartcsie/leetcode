/**
 * 題目：652. Find Duplicate Subtrees (尋找重複的子樹)
 * 難度：中等 (Medium)
 * 描述：給定二元樹的根節點 root，找出所有重複出現的子樹（結構與節點值都完全相同的子樹），
 *       每種重複結構只需回傳其中一個子樹的根節點即可。
 *
 * 時間複雜度：O(N²)
 *             建構與雜湊比對所有序列化字串整體約為 O(N²)。
 * 空間複雜度：O(N²)
 *
 * 解法思路：
 * 1. 後序遍歷並序列化每棵子樹 (Post-order Serialization)：
 *    - 對每個節點，遞迴序列化其左右子樹後，組成形如
 *      "節點值,左子樹序列化,右子樹序列化" 的唯一字串，代表這個子樹的完整結構。
 * 2. 空節點統一編碼 (Null Node Marker)：
 *    - 遇到空節點時回傳固定字串 "#"，確保結構不同的子樹不會因為省略空節點而產生歧義的相同字串。
 * 3. 利用雜湊表統計每種結構出現的次數 (Hash Map Counting)：
 *    - 用 unordered_map<string, int> counts 記錄每個序列化字串出現的次數。
 * 4. 恰好在「第二次出現」時加入答案 (Add on Second Occurrence Only)：
 *    - 利用 ++counts[encodeStr] == 2 這個技巧，只有當某個結構恰好第一次「變成重複」
 *      （即出現第二次）時，才把該節點加入答案，避免同一種重複結構被多次加入。
 * 5. 回傳序列化結果供上層節點使用：
 *    - 每次遞迴呼叫都回傳目前子樹的序列化字串，讓父節點能組合出自己完整的序列化字串。
 */
class Solution {
private:
    string encode(TreeNode* root, unordered_map<string, int>& counts, vector<TreeNode*>& ans) {
        if(!root) return "#";
        string encodeStr =  to_string(root->val) + ","
                            + encode(root->left, counts, ans) + ","
                            + encode(root->right, counts, ans);
        if(++counts[encodeStr] == 2) ans.push_back(root);  
        return encodeStr;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> counts;
        vector<TreeNode*> ans;
        encode(root, counts, ans);
        return ans;
    }
};
