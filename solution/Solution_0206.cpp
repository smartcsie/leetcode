/**
 * 解題思路：迭代法 (Iterative Approach)
 * 1. 使用三個指標來輔助轉向：
 *    - prev (前一個節點)：初始為 NULL。
 *    - curr (當前節點)：初始為 head。
 *    - nextTemp (暫存下一個節點)：防止斷鏈後找不到後續節點。
 * 2. 核心操作：
 *    - 在改變指標方向前，先記錄 nextTemp = curr->next。
 *    - 將 curr->next 指向 prev (完成反轉)。
 *    - 移動指標：prev 移到 curr，curr 移到 nextTemp。
 * 3. 最終當 curr 走到空，prev 就會指向新的頭節點。
 * 
 * Time Complexity: O(n) - 遍歷鏈表一次。
 * Space Complexity: O(1) - 僅使用常數個指標變數。
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
