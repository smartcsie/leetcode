/**
 * 題目：287. Find the Duplicate Number (尋找重複數)
 * 難度：中等 (Medium)
 * 描述：陣列長度為 n+1，且數值範圍在 [1, n] 之間，根據鴿籠原理，至少存在一個重複數字。
 *      請在不修改原陣列且使用 $O(1)$ 額外空間的情況下找出該數字。
 * 
 * 解法思路 (快慢指標)：
 * 1. 將陣列視為一個圖，每個索引 i 對應的值 nums[i] 即為指向下一個節點的指標。
 * 2. 因為存在重複數字，導致多個節點指向同一個目標，因此一定會形成環。
 * 3. 步驟：
 *    - 第一階段：快指標 (fast) 每次走兩步，慢指標 (slow) 每次走一步，直到相遇。
 *    - 第二階段：將其中一個指標重置回起點，兩者改為同樣速度移動，再次相遇點即為環的入口，也就是重複的數字。
 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        
        // 第一階段：尋找相遇點
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        // 第二階段：尋找環的入口
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};
