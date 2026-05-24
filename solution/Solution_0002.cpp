/**
 * 題目：2. Add Two Numbers (兩數相加)
 * 難度：中等 (Medium)
 * 描述：給定兩個非空的鏈結串列，分別表示兩個非負整數。每個節點包含一個位數，位數是按「逆序」排列的，
 * 計算並回傳這兩個數的和（也是以鏈結串列形式）。
 * * 時間複雜度：O(max(N, M)) - N 和 M 為兩個鏈結串列的長度，遍歷一次即可。
 * 空間複雜度：O(max(N, M)) - 結果鏈結串列長度最多為 max(N, M) + 1。
 * * 解法思路：
 * 1. 使用一個 dummy 節點作為結果鏈結串列的開頭，簡化邊界處理。
 * 2. 維持一個 carry 變數來記錄當前位的進位資訊。
 * 3. 使用 while 迴圈同時遍歷兩個鏈結串列，處理長度不一的情況（短的視為補 0）。
 * 4. 每次計算 sum = v1 + v2 + carry，新節點的值為 sum % 10，進位為 sum / 10。
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0); 
        ListNode* cur = &dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            
            int sum = v1 + v2 + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        
        return dummy.next;
    }
};
