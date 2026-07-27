/**
 * 題目：203. Remove Linked List Elements (移除鏈結串列元素)
 * 難度：簡單 (Easy)
 * 描述：刪除鏈結串列中所有值為 val 的節點。
 * * 時間複雜度：O(N) - 遍歷一次鏈結串列。
 * 空間複雜度：O(1) - 僅使用常數額外空間。
 * * 設計思路：
 * 使用 `dummy` 節點指向 `head`，這樣當需要刪除 `head` 本身時，
 * 也可以透過 `dummy->next` 進行統一處理。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;
        while(cur && cur->next) {
            if(cur->next->val == val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        ListNode* ret = dummy->next;
        delete dummy;
        return ret;
    }
};
