/**
 * 題目：2095. Delete the Middle Node of a Linked List (刪除鏈結串列的中點)
 * 難度：中等 (Medium)
 * 描述：刪除鏈結串列的中點節點。若有偶數個節點，刪除後半段的中點。
 * * 時間複雜度：O(N) - 遍歷一次鏈結串列。
 * 空間複雜度：O(1) - 僅使用幾個指標，不依賴額外資料結構。
 * * 優化思路：
 * 利用快慢指針：快指針每次走兩步，慢指針走一步。
 * 當快指針到達終點時，慢指針會停在中點的前一個節點，方便直接刪除中點。
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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;
        ListNode* result = dummy->next;
        return result;
    }
};
