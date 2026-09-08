/**
 * 題目：1721. Swapping Nodes in a Linked List
 * 難度：中等 (Medium)
 * 描述：交換鏈表中第 k 個和倒數第 k 個節點的值。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （兩次遍歷）：
 * 第一次計算鏈表長度，第二次找到第 k 和倒數第 k 個節點，交換其值。
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int count = 0;
        ListNode* cur = head;
        while(cur) {
            count++;
            cur = cur->next;
        }
        int n = count;
        if(n < 2) return head;
        ListNode* first = nullptr;
        ListNode* second = nullptr;
        
        count = 1;
        cur = head;
        while(cur && (!first || !second)) {
            if(count == k) first = cur;
            if(count == (n - k + 1)) second = cur;
            cur = cur->next;
            count++;
        }
        swap(first->val, second->val);
        return head;
    }
};