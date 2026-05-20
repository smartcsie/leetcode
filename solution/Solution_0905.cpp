/**
 * 題目：905. Sort Array By Parity (按奇偶排序陣列)
 * 難度：簡單 (Easy)
 * 描述：給定一個整數陣列 nums，將所有的偶數放在陣列的前面，所有的奇數放在陣列的後面。
 *      回傳滿足條件的任意陣列即可。
 * 
 * 時間複雜度：O(n) - 兩個指標總共遍歷陣列一次。
 * 空間複雜度：O(1) - 原地交換，不需要額外空間。
 * 
 * 解法思路：
 * 採用雙指標頭尾碰撞法：
 * 1. 左指標 (left) 從 0 開始向右移動，尋找第一個「奇數」。
 * 2. 右指標 (right) 從末尾開始向左移動，尋找第一個「偶數」。
 * 3. 當兩個指標都停下且 left < right 時，代表左邊有一個奇數，右邊有一個偶數。
 * 4. 交換這兩個數，繼續移動直到指標相遇。
 */

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            // 只要左邊是偶數，就繼續往右走 (偶數放前面是正確的)
            while (left < right && nums[left] % 2 == 0) {
                left++;
            }
            // 只要右邊是奇數，就繼續往左走 (奇數放後面是正確的)
            while (left < right && nums[right] % 2 == 1) {
                right--;
            }
            // 此時 left 停在一個奇數，right 停在一個偶數
            if (left < right) {
                swap(nums[left], nums[right]);
                // 交換後，這兩個位置都已經正確，可以手動縮小範圍（可寫可不寫）
                left++;
                right--;
            }
        }
        return nums;
    }
};
