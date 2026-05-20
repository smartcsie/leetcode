/**
 * 題目：21. Merge Two Sorted Lists (合併兩個有序鏈結串列)
 * 難度：簡單 (Easy)
 * 描述：將兩個升序鏈結串列合併為一個新的升序鏈結串列。
 * 
 * 時間複雜度：O(n + m) - n 和 m 分別為兩個鏈結串列的長度，每個節點都會被訪問一次。
 * 空間複雜度：O(n + m) - 遞迴深度最深為 n + m，會消耗系統棧空間。
 * 
 * 解法思路：
 * 採用遞迴法，將大問題拆解為：
 * 1. 比較 list1 和 list2 的頭節點數值。
 * 2. 數值較小的節點作為合併後串列的當前節點。
 * 3. 該節點的 next 指向「剩下的節點與另一個串列」合併後的結果。
 * 4. 基底情況 (Base Case)：當其中一個串列為空時，直接回傳另一個串列。
 */


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        if(list1-> val < list2-> val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list2->next, list1);
            return list2;
        }
    }
};
