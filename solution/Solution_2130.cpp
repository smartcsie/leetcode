/**
 * 題目：2130. Maximum Twin Sum of a Linked List (最大孿生和)
 * 難度：中等 (Medium)
 * 描述：計算鏈結串列中所有「孿生節點對」的最大和。
 * * 時間複雜度：O(N) - 遍歷一次鏈結。
 * 空間複雜度：O(N) - 使用堆疊儲存前半段節點。
 * * 優化思路：
 * 1. 快慢指標：精確找到串列中點。
 * 2. 堆疊暫存：利用堆疊後進先出 (LIFO) 特性，反轉讀取前半段順序。
 */

class Solution {
public:
    int pairSum(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        stack<int> st;
        
        while(fast && fast->next) {
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        int maxNum = 0;
        while(slow) {
            int val = st.top() + slow->val;
            st.pop();
            maxNum = std::max(maxNum, val);
            slow = slow->next;
        }
        return maxNum;
    }
};
