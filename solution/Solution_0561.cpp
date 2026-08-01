/**
 * 題目：561. Array Partition (陣列拆分)
 * 難度：簡單 (Easy)
 * 描述：給定長度為 2n 的整數陣列 nums，將其分成 n 對，
 *       求每一對取較小值後加總，使總和最大化，回傳這個最大總和。
 *
 * 時間複雜度：O(NlogN) - 主要成本來自排序，排序需要 O(NlogN)。
 * 空間複雜度：O(1) - 原地排序，不需額外配置動態記憶體（不含排序本身可能用到的堆疊空間）。
 *
 * 解法思路：
 * 1. 貪婪策略：排序後相鄰配對 (Greedy Adjacent Pairing)：
 *    - 直覺上，要讓「每對取較小值」的總和最大，應該讓數值相近的元素配成一對，
 *      避免大數字被迫跟很小的數字配對而浪費掉。
 * 2. 排序後的性質：
 *    - 將 nums 由小到大排序後，相鄰兩個元素的數值差距最小，
 *      因此依序將排序後的 (nums[0], nums[1])、(nums[2], nums[3])... 兩兩配對即為最佳解。
 * 3. 累加偶數索引的值：
 *    - 排序後，每一對中較小的值必定落在偶數索引（0, 2, 4...），
 *      因此只需以步長 2 遍歷陣列，累加這些偶數索引上的值即為答案。
 */
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size(); i += 2) {
            ans +=  nums[i];
        }
        return ans;
    }
};
