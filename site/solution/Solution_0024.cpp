/**
 * 題目：24. Swap Nodes in Pairs (兩兩交換鏈結中的節點)
 * 難度：中等 (Medium)
 * 描述：將鏈結串列中兩兩相鄰的節點進行交換，並回傳新的頭節點。
 * * 時間複雜度：O(N) - 每個節點被訪問一次。
 * 空間複雜度：O(N) - 遞迴堆疊深度為 N/2。
 * * 解法思路：
 * 1. 遞迴終止條件：若節點為空或僅剩一個節點，無法交換，直接回傳。
 * 2. 遞迴步驟：
 * - 先取出第二個節點 `res` 作為新的頭。
 * - 將第一個節點 `head` 指向「遞迴處理剩餘部分」的結果。
 * - 將 `res` 指向 `head` 完成交換。
 * 3. 回傳 `res`。
 */

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 1. 基本情況 (Base Case)
        if (!head || !head->next) {
            return head;
        }
        
        // 2. 遞迴定義
        // 暫存第二個節點 (這將會是交換後的新頭節點)
        ListNode* second = head->next;
        
        // head->next 指向「處理剩餘串列後」的回傳結果
        head->next = swapPairs(second->next);
        
        // 將第二個節點指向第一個節點，完成交換
        second->next = head;
        
        // 回傳新的頭節點
        return second;
    }
};
