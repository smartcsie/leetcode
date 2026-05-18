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
public:
    int mostFreq = INT_MIN;
    int currFreq = 0;
    TreeNode* prev = nullptr;
    vector<int> res;
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        if(prev && root->val == prev->val) {
            currFreq++;
        } else {
            currFreq = 1;
        }
        prev = root;
        if(currFreq > mostFreq) {
            mostFreq = currFreq;
            res = {root->val};
        } else if(currFreq == mostFreq){
            res.push_back(root->val);
        }
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return res;
    }
};
