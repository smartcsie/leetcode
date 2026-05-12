/**
 * 解題思路：龜兔賽跑演算法 (Floyd's Cycle-Finding Algorithm)
 * 1. 使用兩個指標：slow (慢指標) 和 fast (快指標)，初始都指向 head。
 * 2. 移動規則：
 *    - slow 每次走 1 步。
 *    - fast 每次走 2 步。
 * 3. 邏輯判斷：
 *    - 如果 Linked List 中沒有環，fast 最終會到達結點 (NULL)。
 *    - 如果 Linked List 中存在環，快指標 fast 最終會從後方「追上」慢指標 slow，兩者會重合。
 * 
 * 這就像在操場跑步，速度快的人如果領先一圈，最終會再次遇到速度慢的人。
 * 
 * Time Complexity: O(n) - 最壞情況下快指標遍歷兩次鏈表。
 * Space Complexity: O(1) - 僅使用兩個指標，不需額外空間。
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                return true;
            }

        }
        return false;
    }
};
