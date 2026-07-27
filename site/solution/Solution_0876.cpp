/**
 * 題目：876. Middle of the Linked List (鏈表的中間節點)
 * 難度：簡單 (Easy)
 * 描述：給定一個頭節點為 head 的非空單鏈表，回傳鏈表的中間節點。
 *      如果有兩個中間節點（即鏈表長度為偶數），則回傳第二個中間節點。
 * 
 * 時間複雜度：O(n) - 快指標遍歷整個鏈表一次，慢指標遍歷一半。
 * 空間複雜度：O(1) - 僅使用了兩個指標。
 * 
 * 解法思路：
 * 1. 快慢指標法 (Tortoise and Hare)：
 *    - 初始化 slow 和 fast 指標皆指向 head。
 *    - fast 每次向後移動兩個節點，slow 每次向後移動一個節點。
 * 2. 當 fast 移動到鏈表末尾 (nullptr) 或其 next 為空時，slow 剛好會落在中間。
 * 3. 對於偶數長度鏈表（如 1->2->3->4）：
 *    - 第一輪：slow=2, fast=3
 *    - 第二輪：slow=3, fast=nullptr -> 迴圈停止，回傳 3，符合題目要求的第二個中間節點。
 */

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // 初始化雙指標
        ListNode* slow = head;
        ListNode* fast = head;
        
        // 條件 fast && fast->next 確保快指標可以一次走兩步
        // 同時也處理了長度為奇數與偶數的情況
        while (fast && fast->next) {
            slow = slow->next;       // 慢指標走一步
            fast = fast->next->next; // 快指標走兩步
        }
        
        // 當快指標走完，慢指標的位置就是中間點
        return slow;
    }
};
