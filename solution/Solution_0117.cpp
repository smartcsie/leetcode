/**
 * 題目：117. Populating Next Right Pointers in Each Node II (填充每個節點的下一個右側節點指標 II)
 * 難度：中等 (Medium)
 * 描述：給定一個二元樹（不保證為完美二元樹），為每個節點填上 next 指標，
 *       指向其同一層右側的下一個節點；若不存在則設為 nullptr。
 *
 * 時間複雜度：O(N) - 每個節點恰好被走訪並進出佇列各一次。
 * 空間複雜度：O(N) - 佇列在最壞情況下（最寬的一層）需要儲存接近 N/2 個節點。
 *
 * 解法思路：
 * 1. BFS 逐層走訪 (Level Order Traversal)：
 *    - 使用佇列儲存目前層級的所有節點，透過記錄目前層的節點數量（q.size()），
 *      確保每一輪 while 迴圈恰好只處理「同一層」的節點。
 * 2. 利用剩餘佇列大小判斷是否為該層最後一個節點：
 *    - 內層迴圈用倒數計數 i（從 size-1 到 0），彈出目前節點 cur 後，
 *      若 i 為 0（代表這是本層最後一個處理的節點），next 設為 nullptr；
 *      否則此時佇列的下一個節點正是同層右側的下一個節點，直接設為 cur->next。
 * 3. 推入子節點以準備下一層：
 *    - 每處理完一個節點，就把它的左右子節點（若存在）推入佇列尾端，
 *      因為是按照目前層由左至右的順序處理，子節點自然也會按照正確的左至右順序進入佇列，
 *      形成下一層的完整、有序節點序列。
 */
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root; 
        queue<Node*> q({root});
        while(!q.empty()) {
            for(int i = q.size() -1; i >= 0; i--) {
                Node* cur = q.front();
                q.pop();
                cur->next = (i == 0) ? nullptr : q.front();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return root;
    }
};
