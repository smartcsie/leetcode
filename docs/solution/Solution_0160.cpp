/**
 * 題目：160. Intersection of Two Linked Lists (相交鏈結串列)
 * 難度：簡單 (Easy)
 * 描述：找到兩個單鏈結串列相交的起始節點。若不相交，回傳 nullptr。
 * 
 * 時間複雜度：O(n + m) - 每個節點最多被訪問兩次。
 * 空間複雜度：O(1) - 未使用任何額外空間。
 * 
 * 解法思路 (雙指標)：
 * 1. 設置兩個指標 listA 和 listB 分別從 headA 和 headB 開始走。
 * 2. 邏輯核心：當 listA 走到盡頭 (nullptr) 時，將其指向 headB；
 *    同理，listB 走到盡頭時，指向 headA。
 * 3. 為什麼會相遇？
 *    - 假設 A 的獨特長度為 a，B 的獨特長度為 b，交點後的公共長度為 c。
 *    - listA 走過的路徑為：a + c + b
 *    - listB 走過的路徑為：b + c + a
 *    - 因為 a + c + b = b + c + a，它們一定會在交點處相遇。
 * 4. 如果兩者不相交，它們會在最後同時變成 nullptr 而跳出迴圈 (listA == listB == nullptr)。
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* listA = headA;
        ListNode* listB = headB;
        while(listA != listB) {
            listA = listA ? listA->next : headB;
            listB = listB ? listB->next : headA;
        }
        return listA;
    }
};

