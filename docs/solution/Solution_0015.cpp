/**
 * 題目：15. 3Sum (三數之和)
 * 難度：中等 (Medium)
 * 描述：給你一個整數陣列 nums，判斷是否存在三元組 [nums[i], nums[j], nums[k]] 
 *      滿足 i != j、i != k 且 j != k，同時滿足和為 0。
 *      請你返回所有「不重複」的三元組。
 * 
 * 時間複雜度：O(n^2) - 排序耗費 O(n log n)，雙層迴圈遍歷耗費 O(n^2)。
 * 空間複雜度：O(log n) - 取決於排序演算法使用的棧空間。
 * 
 * 解法思路：
 * 1. 先對陣列進行「升序排序」。
 * 2. 遍歷陣列，固定第一個數 nums[i]：
 *    - 若 nums[i] > 0，因陣列已排序，後面數字必大於 0，不可能相加為 0，直接 break。
 *    - 若 nums[i] 與前一個數相同，則跳過 (去重)。
 * 3. 使用「雙指針」尋找剩餘兩數 (left = i+1, right = n-1)：
 *    - sum < 0：left 右移。
 *    - sum > 0：right 左移。
 *    - sum == 0：找到一組解，存入結果，並同時將 left 和 right 移動到下一個不同的數字 (去重)。
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size() - 2; i ++) {
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum < 0) {
                    left++;
                } else if (sum > 0) { 
                    right--;
                } else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};
