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