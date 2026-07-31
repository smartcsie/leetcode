/**
 * 題目：3452. Sum of Good Numbers (好數字之和)
 * 難度：簡單 (Easy)
 * 描述：給定整數陣列 nums 與整數 k，若 nums[i] 嚴格大於索引 i-k 與 i+k 位置上的元素
 *       （若這些索引存在），則稱 nums[i] 為好元素；若這兩個索引都不存在，nums[i] 仍視為好元素。
 *       回傳陣列中所有好元素的總和。
 *
 * 時間複雜度：O(N) - 只需對陣列進行一次線性掃描，每個索引的判斷皆為常數時間。
 * 空間複雜度：O(1) - 只使用常數個變數（ans, hasLeft, hasRight），不需額外配置記憶體。
 *
 * 解法思路：
 * 1. 判斷左右鄰居是否存在 (Boundary Existence Check)：
 *    - 用 hasLeft 表示索引 i-k 是否合法（i-k >= 0），hasRight 表示索引 i+k 是否合法（i+k < n）。
 * 2. 四種情況分別處理 (Four Cases by Neighbor Existence)：
 *    - 左右都不存在：依題目定義，視為自動成立，直接計入好元素。
 *    - 只有右邊存在：只需檢查 nums[i] 是否嚴格大於 nums[i+k]。
 *    - 只有左邊存在：只需檢查 nums[i] 是否嚴格大於 nums[i-k]。
 *    - 左右都存在：兩個條件都必須同時成立才算好元素。
 * 3. 累加符合條件的元素：
 *    - 走訪整個陣列，將所有判定為好元素的 nums[i] 累加進 ans 並回傳。
 */
class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            bool hasLeft = i - k >= 0;
            bool hasRight = i + k < n;
            if(!hasLeft && !hasRight) {
                ans += nums[i];
            } else if(!hasLeft && nums[i] > nums[i + k]) {
                ans += nums[i];
            } else if(!hasRight && nums[i] > nums[i - k]) {
                ans += nums[i];
            } else if(hasLeft && hasRight && nums[i] > nums[i - k] && nums[i] > nums[i + k]) {
                ans += nums[i];
            }
        }
        return ans;
    }
};
