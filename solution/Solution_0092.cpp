/**
 * 題目：92. Reverse Linked List II (反轉鏈結串列 II)
 * 難度：中等 (Medium)
 * 描述：將鏈結串列中從 left 到 right 的區間進行反轉。
 * * 時間複雜度：O(N) - N 為鏈結串列長度。
 * 空間複雜度：O(1) - 原地修改指標，無需額外空間。
 * * 優化思路：
 * 1. 使用 dummy 節點簡化對 head 的操作，避免繁瑣的邊界檢查。
 * 2. 先將指標 `prev` 移動到反轉區間的前一個節點。
 * 3. 透過「穿針引線」法：每次將 `cur->next` 的節點提取出來，插入到 `prev` 與 `prev->next` 之間，即可原地反轉。
 */

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 邊界條件檢查
        if (!head || left == right) return head;
        
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        
        // 移動到反轉區間的前一個節點
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }
        
        // cur 始終指向區間的第一個節點
        ListNode* cur = prev->next;
        
        // 執行反轉：每次將 cur 的下一個節點移動到 prev 後面
        for (int i = 0; i < right - left; ++i) {
            ListNode* temp = cur->next;
            cur->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }
        
        // 回收記憶體並回傳新 head
        ListNode* ret = dummy->next;
        delete dummy; 
        return ret;
    }
};
