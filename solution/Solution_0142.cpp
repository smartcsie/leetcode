/**
 * 題目：142. Linked List Cycle II (環形鏈結串列 II)
 * 難度：中等 (Medium)
 * 描述：偵測鏈結串列中是否存在環，並回傳環的起始節點。
 * * 時間複雜度：O(N) - 遍歷鏈結串列次數為線性。
 * 空間複雜度：O(1) - 僅使用兩個指標，不依賴額外空間。
 * * 優化思路：
 * 1. 快慢指標 (Fast/Slow)：快指標一次兩步，慢指標一次一步。若存在環，兩者必會在環內相遇。
 * 2. 相遇點特性：設頭節點到環入口距離為 a，環入口到相遇點距離為 b，環長為 c。
 * 根據數學推導：相遇時，慢指標走了 (a+b)，快指標走了 (a+b+nc)。
 * 由於快指標速度為兩倍，可得 a = (n-1)c + (c-b)。
 * 這意味著：從頭節點出發的指標與從相遇點出發的指標，在環入口處必會相遇。
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // 1. 尋找相遇點
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            // 找到環中的相遇點
            if (slow == fast) {
                // 2. 定位環的入口：將慢指標重置到起點，快指標停在相遇點
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                // 兩者相遇處即為環的入口
                return slow;
            }
        }
        
        return nullptr;
    }
};
