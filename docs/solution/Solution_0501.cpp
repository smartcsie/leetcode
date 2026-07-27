/**
 * 題目：501. Find Mode in Binary Search Tree (二元搜尋樹中的眾數)
 * 難度：簡單 (Easy)
 * 描述：給你一個有重複節點的二元搜尋樹 (BST) 的根節點 root，找出樹中所有出現頻率最高的元素。
 * 
 * 時間複雜度：O(n) - 每個節點訪問一次。
 * 空間複雜度：O(h) - h 為樹的高度。如果不計遞迴產生的棧空間，則為 O(1)。
 * 
 * 解法思路：
 * 1. BST 特性：中序遍歷 (In-order) 會得到一個「遞增數列」。
 * 2. 在遞增數列中，相同的數字必定會「相鄰出現」。
 * 3. 核心邏輯：
 *    - 使用 prev 指標紀錄前一個遍歷到的節點，解決「如何判斷數字是否連續」的問題。
 *    - 當前數字等於前一個數字時，頻率 currFreq 累加；否則重置為 1。
 *    - 如果 currFreq 大於目前最大頻率 mostFreq：更新 mostFreq 並「清空結果陣列」，重新存入當前值。
 *    - 如果 currFreq 等於 mostFreq：將當前值加入結果陣列。
 */

class Solution {
private:
    void dfs(TreeNode* root, int& prev ,int& localCount, int& max, vector<int>& res) {
        if(!root) return;
        dfs(root->left, prev, localCount, max, res);
        if(root->val == prev) localCount++;
        else localCount = 1;
        if(localCount > max) {
            max = localCount;
            res.clear();
            res.push_back(root->val);
        }
        else if(localCount == max) {
            res.push_back(root->val);
        }
        prev = root->val;
        dfs(root->right, prev, localCount, max, res);
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int localCount = 1;
        int max = INT_MIN;
        int prev = INT_MIN;
        dfs(root, prev, localCount, max, res);
        return res;
    }
};

