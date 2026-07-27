/**
 * 題目：1721. Swapping Nodes in a Linked List (交換鏈結串列中的節點)
 * 難度：中等 (Medium)
 * 描述：交換鏈結串列中第 k 個節點與倒數第 k 個節點的數值。
 * * 時間複雜度：O(N) - 僅遍歷一次鏈結串列。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路 (One-pass)：
 * 1. 使用快慢指針 `first` 和 `second`。
 * 2. `first` 先走 k 步到達目標節點。
 * 3. 接著 `first` 和 `second` 同步移動，當 `first` 到達尾端時，`second` 正好位於倒數第 k 個節點。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
         ListNode* second = head;
         ListNode* fast = head;

        for(int i = 1; i < k; i++) {
            fast = fast->next;
        }

        ListNode * first = fast;

        while(fast->next) {
            fast = fast->next;
            second = second->next;
        }

        swap(first->val, second->val);

        return head;
    }
};
