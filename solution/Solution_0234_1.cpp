/*
 * 題目：234. Palindrome Linked List
 * 連結：https://leetcode.com/problems/palindrome-linked-list/
 * 難度：Easy
 * 分類主題：Linked List, Two Pointers
 * 技巧：快慢指針找中點 + 反轉後半段鏈結串列 + 雙指針比較
 * 描述：給定單向鏈結串列的頭節點 head，判斷這個鏈結串列所代表的數字序列是否為回文。
 * 時間複雜度：O(N)，找中點、反轉、比較各走訪約 N/2 個節點，總和仍是 O(N)
 * 空間複雜度：O(1)，只使用固定數量的指標變數，沒有額外配置陣列或遞迴堆疊
 * 解法思路：
 *   1. 用 dummy 節點接在 head 前面，搭配快慢指針找出前半段的結尾（slow）。
 *      - fast 每次走 2 步、slow（從 dummy 出發）每次走 1 步，
 *        當 fast 走到底時，slow 恰好停在「前半段最後一個節點」，
 *        這樣無論串列長度是奇數或偶數都能正確切割成前後兩段。
 *   2. 從 slow->next 開始把後半段切斷並原地反轉，得到反轉後的後半段串列（prev）。
 *   3. 用 l1（原始前半段，從 head 開始）與 l2（反轉後的後半段，從 prev 開始）
 *      逐一比較節點值，只要有一組不相等就代表不是回文，直接回傳 false。
 *   4. 若兩段都比較完仍相等（其中一個走到 nullptr 為止），代表是回文，回傳 true。
 *   注意：此寫法會破壞原始鏈結串列結構（後半段被反轉），
 *         若題目要求保留原始串列，比較完後需再把後半段反轉回去並重新接上。
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // dummy 節點方便快慢指針統一處理奇偶長度的情況
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = head;

        // 快慢指針：fast 走 2 步、slow 走 1 步
        // 結束時 slow 停在「前半段最後一個節點」
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 切斷前後兩段：slow->next 之後就是後半段的起點
        ListNode* cur = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;

        // 原地反轉後半段串列，反轉完 prev 就是後半段的新頭節點
        while (cur) {
            ListNode* next = cur->next; // 先暫存下一個節點
            cur->next = prev;           // 反轉指標方向
            prev = cur;                 // prev 前進
            cur = next;                 // cur 前進
        }

        // l1：原始前半段；l2：反轉後的後半段
        ListNode* l1 = head;
        ListNode* l2 = prev;

        // 逐一比較前半段與反轉後半段的節點值
        while (l1 && l2) {
            if (l1->val != l2->val) return false; // 值不相等，不是回文
            l1 = l1->next;
            l2 = l2->next;
        }

        return true; // 全部比對完都相等，是回文
    }
};