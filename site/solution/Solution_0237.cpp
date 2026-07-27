/**
 * 題目：237. Delete Node in a Linked List (刪除鏈結串列中的節點)
 * 難度：簡單 (Easy)
 * 描述：在不給予 head 的情況下，刪除給定的節點。
 * * 時間複雜度：O(1) - 僅進行常數次賦值。
 * 空間複雜度：O(1) - 未使用額外空間。
 * * 設計思路：
 * 既然無法獲取前一個節點，我們直接將「下一個節點的值」複製到「當前節點」，
 * 然後將當前節點的指標指向「下下個節點」。
 * 這種方法在邏輯上實現了刪除。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* releaseNode = node->next;
        node->next = node->next->next;
        delete releaseNode;
    }
};
