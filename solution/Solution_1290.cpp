/**
 * 題目：1290. Convert Binary Number in a Linked List to Integer
 * 描述：給你一個單向鏈結串列的頭節點 head。鏈結串列中的每個節點上都存放一個 0 或 1。
 *       已知這個串列表示一個二進位數字，請返回該數字的十進位表示。
 * 
 * 解法思路：
 * 1. 初始化一個變數 ans = 0 用來累積十進位結果。
 * 2. 使用指標 cur 從頭節點開始依序向後走訪鏈結串列。
 * 3. 每次讀取到一個節點的值（cur->val）：
 *    - 將現有的 ans 向左位移一位（等同於乘以 2），為即將進來的新 bit 騰出空間。
 *    - 利用按位或 (`|`) 將當前節點的值加到最低位上。
 * 4. 當 cur 指標走到結尾（nullptr）時，迴圈結束，返回 ans 即為最終的十進位數。
 */

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        ListNode* cur = head;
        
        while (cur != nullptr) {
            // ans 左移一位，並將當前節點的值放入最低位
            ans = (ans << 1) | cur->val;
            cur = cur->next;
        }
        
        return ans;
    }
};
