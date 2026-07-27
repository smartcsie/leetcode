/**
 * 題目：148. Sort List (排序連結串列)
 * 難度：中等 (Medium)
 * 描述：在 O(N log N) 時間複雜度與 O(log N) 遞迴空間複雜度下進行排序。
 * * 優化思路：
 * 1. 快慢指標：精確定位中點以切割串列。
 * 2. 虛擬節點 (Dummy Node)：合併時使用 dummy 節點簡化頭部操作。
 * 3. 遞迴分治：確保每層都能將問題規模減半。
 */

class Solution {
private:
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(l1 && l2) {
            if(l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast &&　fast->next) {
            slow = slow->next;
　          fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        return mergeList(left, right);
    }
};
