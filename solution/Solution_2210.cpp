/**
 * 題目：2210. Count Hills and Valleys in an Array (統計陣列中的山峰和山谷數量)
 * 難度：簡單 (Easy)
 * 描述：給你一個下標從 0 開始的整數陣列 nums。如果陣列中的某個子陣列滿足特定的鄰居條件，
 *       則稱其為山峰（Hill）或山谷（Valley）。請你返回陣列中山峰和山谷的總數。
 * 
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 * 
 * 解法思路：
 * 1. 相鄰重複元素的略過：
 *    - 題目定義中，平坦的斜坡不影響山峰/山谷判定。若當前元素等於右側鄰居（`nums[i] == nums[i + 1]`），則直接跳過，不作為轉折點。
 * 2. 追蹤有效左側鄰居 (`prev`)：
 *    - 因為可能存在連續相同高度的數字，真正的「左側轉折點」應該是上一個**與當前不同高度**的元素位置。
 *    - 當我們確認當前元素不是重複值且完成山峰/山谷判斷後，才更新 `prev = i`。
 * 3. 判斷山峰與山谷：
 *    - 山峰 (Hill)：當前元素大於左右兩側（`nums[i] > nums[prev] && nums[i] > nums[i + 1]`）。
 *    - 山谷 (Valley)：當前元素小於左右兩側（`nums[i] < nums[prev] && nums[i] < nums[i + 1]`）。
 */

class Solution {
public:
    int countHillValley(std::vector<int>& nums) {
        int ans = 0;
        for(int i = 1, prev = 0; i < nums.size() - 1; i++) {
            if(nums[i] == nums[i + 1]) continue;
            if(nums[prev] < nums[i] && nums[i] > nums[i + 1]) ans++;
            if(nums[prev] > nums[i] && nums[i] < nums[i + 1]) ans++;
            prev = i;
        }
        return ans;
    }
};
