/**
 * 題目：445. Add Two Numbers II (兩數相加 II)
 * 難度：中等 (Medium)
 * 描述：給定兩個以正常順序表示數字的鏈結串列，計算它們的和並以同樣的順序回傳。
 *
 * 時間複雜度：O(N + M) - N 和 M 分別為兩個鏈結串列的長度，遍歷與處理皆為線性時間。
 * 空間複雜度：O(N + M) - 最多需要 stack 儲存兩個鏈結串列的所有節點值。
 *
 * 解法思路：
 * 1. 使用兩個 stack 分別存入 l1 與 l2 的節點值，實現反向遍歷的效果。
 * 2. 使用一個 dummy 節點作為結果鏈結串列的輔助頭。
 * 3. 進入迴圈，每次從 stack 頂部取出數值（對應數字的個位、十位...），計算和與進位。
 * 4. 使用「頭插法」 (new ListNode(val, dummy->next)) 將計算結果插入 dummy 後方，
 * 這樣能確保結果鏈結串列的順序自動由高位排至低位。
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1;
        stack<int> st2;
        
        // 將節點值壓入 stack
        for(ListNode* cur = l1; cur != nullptr; cur = cur->next) st1.push(cur->val);
        for(ListNode* cur = l2; cur != nullptr; cur = cur->next) st2.push(cur->val);
        
        ListNode* dummy = new ListNode(0);
        int carry = 0;
        
        // 只要任一 stack 還有數字，或還有進位，就繼續運算
        while(!st1.empty() || !st2.empty() || carry != 0) {
            int a = 0, b = 0;
            if(!st1.empty()) {
                a = st1.top();
                st1.pop();
            }
            if(!st2.empty()) {
                b = st2.top();
                st2.pop();
            }
            
            int sum = a + b + carry;
            
            // 頭插法：將新節點接在 dummy->next 的前面
            dummy->next = new ListNode(sum % 10, dummy->next);
            carry = sum / 10;
        }
        
        return dummy->next;
    }
};
