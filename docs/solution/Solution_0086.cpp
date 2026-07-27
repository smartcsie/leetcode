/**
 * 題目：86. Partition List (分割鏈結串列)
 * 難度：中等 (Medium)
 * 描述：將鏈結串列分割為小於 x 與大於等於 x 的兩個部分。
 * * 時間複雜度：O(N) - 遍歷鏈結串列一次。
 * 空間複雜度：O(1) - 僅使用額外的指標，不依賴額外的節點空間。
 * * 優化思路：
 * 1. 建立兩個虛擬節點 (dummy nodes) 分別代表「小於部分」與「大於等於部分」。
 * 2. 遍歷原鏈結，根據節點值將其掛載到對應的串列尾端。
 * 3. 處理最後的連結：將左串列的尾端指向右串列的開頭，並將右串列的尾端置空。
 */

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // 使用虛擬節點簡化邊界處理
        ListNode leftDummy(0), rightDummy(0);
        ListNode *lTail = &leftDummy, *rTail = &rightDummy;

        while (head) {
            if (head->val < x) {
                lTail->next = head;
                lTail = lTail->next;
            } else {
                rTail->next = head;
                rTail = rTail->next;
            }
            head = head->next;
        }

        // 合併兩個鏈結串列
        lTail->next = rightDummy.next;
        // 重要：必須將右側串列尾端指向空，避免產生循環鏈結 (Cycle)
        rTail->next = nullptr;
        
        return leftDummy.next;
    }
};
