/**
 * 題目：2130. Maximum Twin Sum of a Linked List (鏈結串列的最大孿生數之和)
 * 難度：中等 (Medium)
 * 描述：給定一個偶數長度的鏈結串列，第 i 個節點的孿生節點為第 (n-1-i) 個節點。
 *       回傳所有孿生節點對的最大總和。
 *
 * 時間複雜度：O(N) - 快慢指標、反轉、雙指標各掃一次。
 * 空間複雜度：O(1) - 原地反轉後半段，不需額外空間。
 *
 * 解法思路：
 * 1. 快慢指標找中點 (Floyd's Algorithm)：
 *    - slow 每次走一步，fast 每次走兩步，
 *      當 fast 到達末端時，slow 剛好在中點。
 * 2. 反轉後半段鏈結串列：
 *    - 從 slow 開始，原地反轉後半段。
 *    - 反轉後 prev 指向後半段的頭（即原串列的最後一個節點）。
 * 3. 雙指標計算孿生和：
 *    - l1 從頭出發，l2 從反轉後的後半段頭出發，
 *      兩者同時往前走，計算每對孿生節點的總和，維護最大值。
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        // Step 1: 快慢指標找中點
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: 原地反轉後半段
        ListNode* prev = nullptr;
        ListNode* cur  = slow;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur  = next;
        }

        // Step 3: 雙指標計算最大孿生和
        ListNode* l1 = head;
        ListNode* l2 = prev;  // 反轉後的後半段頭
        int mx = INT_MIN;
        while (l2) {
            mx = max(mx, l1->val + l2->val);
            l1 = l1->next;
            l2 = l2->next;
        }

        return mx;
    }
};