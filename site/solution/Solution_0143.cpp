/**
 * 題目：143. Reorder List (重排串列)
 * 難度：中等 (Medium)
 * 描述：將串列 L0 -> L1 -> ... -> Ln-1 -> Ln 重排為 L0 -> Ln -> L1 -> Ln-1 -> ...
 * * 時間複雜度：O(N) - 分割、反轉、合併皆為線性。
 * 空間複雜度：O(1) - 原地操作，無額外空間使用。
 * * 優化思路：
 * 1. 切分：快慢指標找到中點。
 * 2. 反轉：反轉後半段鏈結。
 * 3. 合併：交錯連接前後兩半。
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        // 1. 尋找中點
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. 反轉後半段：從 slow->next 開始
        ListNode *cur = slow->next;
        slow->next = nullptr; // 切分兩段
        ListNode *pre = nullptr;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        // 3. 交錯合併：將 l1 與反轉後的 l2 合併
        ListNode *l1 = head;
        ListNode *l2 = pre; // pre 是反轉後的頭
        while (l2) {
            ListNode* next1 = l1->next;
            ListNode* next2 = l2->next;

            l1->next = l2;
            l2->next = next1;

            l1 = next1;
            l2 = next2;
        }
    }
};
