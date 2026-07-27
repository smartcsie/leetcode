/**
 * 題目：2181. Merge Nodes in Between Zeros
 * 描述：給你一個鏈結串列，其中包含一系列由 0 分隔的正整數。
 *       每兩個相鄰的 0 之間的所有節點需要合並成一個節點，其值為這些節點數值的總和。
 *       修改完後，返回修改後的鏈結串列，且串列中不能包含任何值為 0 的節點。
 * 
 * 解法思路（原地修改鏈結串列 In-place Modification）：
 * 1. 雙層指標與累加：
 *    - 使用指標 `cur` 標記當前要彙整結果的節點。
 *    - 內層迴圈透過 `cur->next` 探索下一個節點，只要該節點不是 0，就將其數值累加到 `cur->val` 中，並透過修改指標（`cur->next = cur->next->next`）來跳過並刪除該節點。
 * 2. 處理串列尾端的 0：
 *    - 當內層迴圈遇到 0 時，檢查這個 0 是否為鏈結串列的最後一個節點（`cur->next->next == nullptr`）。若是，則將其切斷（`cur->next = nullptr`）；否則將 `cur` 移動到下一個區段的起始位置繼續累加。
 * 時間複雜度：O(N) - 單次遍歷，in-place 合併零之間的節點。
 * 空間複雜度：O(1) - 僅使用常數個指針。

 */

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* cur = head;
        
        while (cur) {
            // 將兩個 0 之間的所有節點數值累加到當前節點，並拔除已累加的節點
            while (cur->next && cur->next->val != 0) {
                cur->val += cur->next->val;
                cur->next = cur->next->next;
            }
            
            // 如果下一個節點是 0，且它是整個鏈結串列的最後一個節點，將其切斷
            if (cur->next && cur->next->val == 0 && cur->next->next == nullptr) {
                cur->next = nullptr;
            }
            
            // 移動到下一個區段的起始節點
            cur = cur->next;
        }
        
        return head;
    }
};
