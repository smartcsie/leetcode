/**
 * 題目：19. Remove Nth Node From End of List (刪除鏈結串列的倒數第 N 個節點)
 * 難度：中等 (Medium)
 * 描述：給定一個鏈結串列，刪除倒數第 N 個節點，並返回修改後的鏈結串列頭。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * (快慢指標)：
 * 1. 使用 dummy 節點：處理「刪除頭節點」這類邊界情況（例如長度為 1 且要刪除該節點）。
 * 2. 快指標 (fast) 先走 N 步，與 slow 指標建立 N 個節點的間距。
 * 3. 接著 slow 與 fast 同步往後移動，直到 fast 到達最後一個節點 (fast->next == nullptr)。
 * 4. 此時 slow 指標正好停在倒數第 N 個節點的「前一個位置」。
 * 5. 執行刪除：slow->next = slow->next->next。
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        for(int i = 1; i <= n ; i++) fast = fast->next;
        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
