/**
 * 題目：3487. Maximum Unique Subarray Sum After Deletion
 * 描述：給定一個整數陣列 nums，在刪除部分元素後，選出一個具有唯一元素的子陣列，
 *       使得其元素總和最大。請返回該最大總和。
 * 
 * 解法思路：
 * 1. 邊界特判：先找出陣列中的最大值 `maxVal`。若全陣列皆為負數，則最大的唯一元素（即最接近 0 的負數）即為答案，直接回傳 `maxVal`。
 * 2. 元素去重：利用 `std::unordered_set` 將 `nums` 裡的元素全部放入，自動過濾掉重複的數值。
 * 3. 貪婪加總：使用 `std::accumulate` 走訪去重後的集合：
 *    - 為了讓總和最大，我們只挑選大於 0 的正數進行累加（負數加入只會讓總和變小，因為題目允許刪除元素）。
 * 4. 返回計算出來的最大總和。
 */

class Solution {
public:
    int maxSum(std::vector<int>& nums) {
        // 1. 檢查是否全為負數
        int maxVal = std::ranges::max(nums);
        if (maxVal < 0) {
            return maxVal;
        }
        // 2. 使用 hash set 進行元素去重
        std::unordered_set<int> uniqueSet(nums.begin(), nums.end());
        // 3. 僅將不重複且大於 0 的正數進行加總
        return std::accumulate(uniqueSet.begin(), uniqueSet.end(), 0, [](int acc, int num) {
            acc += (num > 0) ? num : 0;
            return acc;
        });
    }
};
