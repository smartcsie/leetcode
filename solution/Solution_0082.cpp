/**
 * 題目：82. Remove Duplicates from Sorted List II (移除已排序鏈表中的重複元素 II)
 * 難度：中等 (Medium)
 * 描述：給定一個已排序的鏈表，刪除所有具有重複數字的節點，只保留原始鏈表中「完全沒有重複」的數字。
 *      例如：1->2->3->3->4->4->5 回傳 1->2->5。
 * 
 * 時間複雜度：O(n) - 每個節點最多被訪問兩次。
 * 空間複雜度：O(1) - 只使用了常數個額外指標。
 * 
 * 解法思路：
 * 1. 建立一個 dummy 節點指向 head，這樣即使 head 被刪除也能輕鬆回傳結果。
 * 2. 使用 pre 指標指向「確定不重複」的最後一個節點，cur 指標用來探索。
 * 3. 利用一個內部 while 迴圈找到所有重複數值的末尾。
 * 4. 判斷 pre->next 是否仍指向 cur：
 *    - 若是：代表 cur 所在位置沒有發生重複，pre 可以安全移動到 cur。
 *    - 若否：代表 cur 經歷過重複跳轉，直接將 pre->next 指向 cur->next（跳過這整段重複值）。
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        ListNode* cur = head;
        while(cur) {
            while(cur->next && cur->val == cur->next->val) {
                cur = cur->next;
            }
            if(pre->next == cur) {
                pre = cur;
            } else {
                pre->next = cur->next;
            }
            cur = cur->next;
        }
        return dummy->next;

    }
};
