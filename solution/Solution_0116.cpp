/**
 * 題目：116. Populating Next Right Pointers in Each Node (填充每個節點的下一個右側節點指標)
 * 難度：中等 (Medium)
 * 描述：給定一棵完美二元樹（Perfect Binary Tree，所有葉子節點在同一層，
 *       且每個父節點都有兩個子節點），為每個節點填上 next 指標，
 *       指向其同一層右側的下一個節點；若不存在則設為 nullptr。
 *
 * 時間複雜度：O(N) - 每個節點恰好被走訪一次。
 * 空間複雜度：O(1) - 不使用額外的佇列或遞迴堆疊，僅使用常數個指標變數。
 *
 * 解法思路：
 * 1. 利用「上一層已連好的 next」逐層向下連接 (Level-by-Level Using Established Links)：
 *    - 因為題目保證是完美二元樹，一旦某一層的 next 指標都已經連好，
 *      就可以利用這些指標，直接把「下一層」也連接起來，完全不需要額外的資料結構。
 * 2. 用 leftmost 追蹤每一層的起點：
 *    - leftmost 一開始指向根節點，每處理完一層，就往下移動到 leftmost->left，
 *      作為下一層的起點；當 leftmost->left 不存在時，代表已經到達最後一層，結束迴圈。
 * 3. 同一父節點下的左右子節點互相連接：
 *    - 對目前層的每個節點 cur，直接令 cur->left->next = cur->right，
 *      因為兩者是同一個父節點的子節點，必定相鄰。
 * 4. 跨父節點的連接：
 *    - 若 cur->next 存在（代表 cur 右側還有其他節點），
 *      則 cur->right->next = cur->next->left，透過上一層已經建立好的 next 指標，
 *      跨越到下一個父節點，把兩個子樹之間的邊界節點連接起來。
 * 5. 同層由左至右遍歷：
 *    - 內層 while 迴圈透過 cur = cur->next 沿著目前層已建立的指標前進，
 *      確保整層節點都能依序被處理到。
 */
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        Node* leftmost = root;
        while (leftmost->left) {
            Node* cur = leftmost;
            while (cur) {
                cur->left->next = cur->right;
                if (cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            leftmost = leftmost->left;
        }
        return root;
    }
};
