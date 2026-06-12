/**
 * 題目：328. Odd Even Linked List (奇偶鏈結串列)
 * 難度：中等 (Medium)
 * 描述：將鏈結串列重排，使得所有奇數索引的節點排在偶數索引節點之前。
 * * 時間複雜度：O(N) - 只需遍歷一次鏈結串列。
 * 空間複雜度：O(1) - 僅使用指標進行重組，無額外記憶體佔用。
 * * 優化思路：
 * 1. 分流：建立兩個指標 `odd` 和 `even` 分別指向頭部與次節點。
 * 2. 串接：將奇數節點指向下一個奇數，偶數節點指向下一個偶數。
 * 3. 合併：遍歷結束後，將奇數鏈的最後一個節點指向 `evenHead`。
 */

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // 基底條件：長度小於 3 的串列無需移動，直接返回
        if (!head || !head->next || !head->next->next) return head;

        ListNode* odd = head;          // 奇數鏈起點
        ListNode* even = head->next;   // 偶數鏈起點
        ListNode* evenHead = even;     // 保留偶數鏈起點，用於最後合併

        // 遍歷直到偶數鏈沒有下一個節點
        while (even && even->next) {
            // 奇數節點指向下下個 (跳過偶數)
            odd->next = even->next;
            odd = odd->next;
            
            // 偶數節點指向下下個 (跳過奇數)
            even->next = odd->next;
            even = even->next;
        }

        // 將奇數鏈的尾巴接上偶數鏈的開頭
        odd->next = evenHead;

        return head;
    }
};
