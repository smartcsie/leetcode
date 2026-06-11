/**
 * 題目：109. Convert Sorted List to Binary Search Tree (有序鏈結串列轉平衡二元搜尋樹)
 * 難度：中等 (Medium)
 * 描述：將升序連結串列轉換為一棵高度平衡的 BST。
 * * 時間複雜度：O(N log N) - 每一層遞迴需要 O(N) 遍歷串列，共 log N 層。
 * 空間複雜度：O(log N) - 遞迴調用棧深度。
 * * 優化思路：
 * 1. 分治法：每次選定中點作為根節點，將剩餘節點劃分為左右子串列。
 * 2. 空間優化：省略了將資料存入 vector 的過程，直接在鏈結上操作。
 */

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // 基底條件：空串列則返回空節點
        if (!head) return nullptr;
        // 基底條件：單一節點則直接作為葉節點
        if (!head->next) return new TreeNode(head->val);

        // 1. 使用快慢指標尋找中點
        // prev 負責記錄中點前一個節點，用於後續斷開連結
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. 切斷鏈結：將串列分為 [head, prev] 與 [slow->next, end]
        prev->next = nullptr;

        // 3. 遞迴構建：slow 為中點，即為當前子樹的根節點
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};
