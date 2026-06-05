/**
 * 題目：61. Rotate List (旋轉鏈結串列)
 * 難度：中等 (Medium)
 * 描述：將鏈結串列向右旋轉 k 個位置。
 * * 時間複雜度：O(N) - 遍歷串列計算長度及旋轉。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 1. 先計算長度並將最後一個節點連到 head，使串列成環。
 * 2. 旋轉 k 次等同於移動 `length - k % length` 次，找到新的斷點。
 * 3. 斷開環即得到新的 head。
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
    ListNode* rotateRight(ListNode* head, int k) {
        // 邊界條件：空節點、單節點或不需要旋轉
        if (!head || !head->next || k == 0) return head;

        // 1. 計算長度並找尾節點
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            length++;
            tail = tail->next;
        }

        // 2. 優化 k 的數值：k 可能大於長度，對 length 取模
        k %= length;
        if (k == 0) return head; // 不需要旋轉

        // 3. 閉合成環
        tail->next = head;

        // 4. 移動至新的斷點：需移動 (length - k) 次
        // 原本 tail 在尾，要移到斷點需走 length - k 步
        int stepsToNewTail = length - k;
        for (int i = 0; i < stepsToNewTail; ++i) {
            tail = tail->next;
        }

        // 5. 切斷環並更新 head
        ListNode* newHead = tail->next;
        tail->next = nullptr;

        return newHead;
    }
};
