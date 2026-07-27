/**
 * 題目：83. Remove Duplicates from Sorted List (移除已排序鏈表中的重複元素)
 * 難度：簡單 (Easy)
 * 描述：給定一個已排序的鏈表的頭節點 head，刪除所有重複的元素，使每個元素只出現一次。
 *      回傳同樣按排序順序排列的鏈表。
 * 
 * 時間複雜度：O(n) - 其中 n 是鏈表的節點數量。
 * 空間複雜度：O(1) - 只使用了常數個指標空間。
 * 
 * 解法思路：
 * 1. 由於鏈表已經排序，重複的元素一定會相鄰。
 * 2. 使用一個指標 cur 從頭開始遍歷。
 * 3. 比較 cur 與 cur->next 的數值：
 *    - 若相等：代表發現重複，將 cur->next 指向再下一個節點 (cur->next->next)，從而跳過重複節點。
 *    - 若不等：代表目前節點不重複，將 cur 指標後移一位。
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while(cur && cur->next) {
            if(cur->val == cur->next->val) {
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};
