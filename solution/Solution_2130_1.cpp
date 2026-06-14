/**
 * 題目：2130. Maximum Twin Sum of a Linked List (鏈表的最大孿生和)
 * 難度：中等 (Medium)
 * 描述：鏈表長度為偶數 n，第 i 個節點的孿生節點為第 (n-1-i) 個，求最大孿生和。
 * * 時間複雜度：O(N) - 遍歷兩次鏈表。
 * 空間複雜度：O(1) - 原地修改鏈表指標。
 * * 優化思路：
 * 1. 快慢指針：找到鏈表中點，將鏈表分割為前後兩段。
 * 2. 反轉鏈表：將後半段鏈表反轉。
 * 3. 對位加總：兩段鏈表同時從頭遍歷，計算對應節點值之和取最大值。
 */

class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while(head) {
            ListNode* next = head->next;
            head->next = prev;  
            prev = head;  
            head = next; 
        }
        return prev;
    }
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* l2 = reverseList(slow->next);
        slow->next = nullptr;

        ListNode* l1 = head;
        int max = 0;
        while(l1 && l2) {
            max = std::max(max, l1->val + l2->val);
            l1 = l1->next;
            l2 = l2->next;
        }
        return max;
    }
};
