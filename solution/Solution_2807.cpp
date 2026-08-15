/**
 * 題目：2807. Insert Greatest Common Divisors in Linked List (在鏈結串列中插入最大公因數)
 * 難度：中等 (Medium)
 * 描述：給定鏈結串列 head，對每一對相鄰節點之間，插入一個新節點，
 *       其值為這兩個相鄰節點值的最大公因數，回傳修改後的鏈結串列。
 *
 * 時間複雜度：O(N) - 每個原始節點恰好被走訪一次，每次插入操作皆為常數時間。
 * 空間複雜度：O(N) - 需要為每一對相鄰節點新建一個節點，新增節點數約為原節點數的一半，仍視為 O(N)。
 *
 * 解法思路：
 * 1. 事先保存下一個原始節點 (Save Next Before Modification)：
 *    - 在修改 cur->next 之前，先用 next 保存 cur 原本的下一個節點，
 *      確保之後 cur = next 前進時，走到的是正確的「原始」下一個節點，不受插入操作干擾。
 * 2. 計算相鄰兩節點的最大公因數並建立新節點：
 *    - 若 next 存在（代表 cur 不是最後一個節點），計算 gcd(cur->val, next->val)，
 *      並建立一個新節點 gcdNode，讓它的 next 直接指向原本的 next 節點。
 * 3. 插入新節點到鏈結串列中：
 *    - 將 cur->next 指向新建立的 gcdNode，完成 cur -> gcdNode -> next 的插入。
 * 4. 前進到下一個原始節點繼續處理：
 *    - 令 cur = next（保存下來的原始下一個節點），因為該節點自身的 next 指標
 *      從未被本次迭代動過，下一輪能正確讀到它真正的下一個原始節點，逐一完成所有插入。
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;
        while(cur && cur->next) {
            int _gcd = gcd(cur->val, cur->next->val);
            ListNode *newNode = new ListNode(_gcd, cur->next);
            cur->next = newNode;
            cur = cur->next->next;
        }
        return head;
    }
    }
};
