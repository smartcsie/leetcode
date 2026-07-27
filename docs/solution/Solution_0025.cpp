/**
 * 題目：25. Reverse Nodes in k-Group (k 個一組翻轉鏈結串列)
 * 難度：困難 (Hard)
 * 描述：每 k 個節點一組進行翻轉，若最後剩餘節點不足 k 個，則保持不變。
 * * 時間複雜度：O(N) - 每個節點最多被遍歷兩次。
 * 空間複雜度：O(1) - 僅使用了常數空間的指標變數。
 * * 優化思路：
 * 1. Dummy 節點：解決頭節點被翻轉後的指標指向問題。
 * 2. 指標交換策略：利用 pre 與 next 的邊界，將區段內節點逐一移至前端。
 */

class Solution {
private:
    // 反轉 pre->next 到 end 之間的所有節點
    // 返回值為反轉後區段的末尾節點 (即原區段的首節點)
    ListNode* reverseOneGroup(ListNode* pre, ListNode* next) {
        ListNode *last = pre->next, *cur = last->next;
        while (cur != next) {
            last->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = last->next;
        }
        return last; // 返回原區段首節點，現在它位於區段末尾
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        
        ListNode* dummy = new ListNode(0, head);
        ListNode *pre = dummy, *cur = head;
        
        int i = 1;
        while (cur) {
            if (i % k == 0) {
                // 當前分組結束，進行反轉
                pre = reverseOneGroup(pre, cur->next);
                cur = pre->next; // 重置 cur 到新分組的開頭
            } else {
                cur = cur->next;
            }
            i++;
        }
        
        ListNode* res = dummy->next;
        delete dummy; // 釋放 dummy
        return res;
    }
};
