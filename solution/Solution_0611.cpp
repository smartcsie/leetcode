/**
 * 題目：611. Valid Triangle Number (有效三角形的個數)
 * 難度：中等 (Medium)
 * 描述：給定一個包含非負整數的陣列 nums，計算並回傳其中可以組成三角形三邊的
 *       三元組個數（滿足三角形不等式：任兩邊之和大於第三邊）。
 *
 * 時間複雜度：O(N²) - 排序需要 O(N log N)，外層固定最大邊（O(N)）搭配內層雙指標
 *             掃描（均攤 O(N)），整體為 O(N²)。
 * 空間複雜度：O(1) - 原地排序，只使用常數個額外變數。
 *
 * 解法思路：
 * 1. 排序後固定「最大邊」由大到小嘗試 (Sort + Fix Largest Side)：
 *    - 排序後，只要 nums[i] 是三邊中最大的一邊，
 *      三角形不等式就簡化成只需檢查「另外兩邊之和 > 最大邊」即可
 *      （因為排序後兩邊都比最大邊小，另外兩個不等式自動成立）。
 * 2. 雙指標從兩端往中間夾逼 (Two Pointers on the Remaining Prefix)：
 *    - 對固定的最大邊索引 i，在 [0, i-1] 範圍內用 left、right 兩個指標，
 *      left 從最小值開始、right 從次大值開始。
 * 3. 若 nums[left] + nums[right] > nums[i]，一次計入多組合法解：
 *    - 由於陣列已排序，若目前的 left 搭配 right 就能組成三角形，
 *      那麼所有 [left, right-1] 之間的索引搭配 right，其和只會更大，
 *      同樣都能組成三角形，因此可以一次把 (right - left) 這麼多組解加進答案，
 *      再將 right 往左移一格，嘗試更小的第二邊。
 * 4. 否則放棄目前的 left，往右移：
 *    - 若和不夠大，代表 left 這個值太小，無法與任何 right 組成三角形，
 *      將 left 右移，嘗試更大的最小邊。
 */
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        for (int i = n - 1; i >= 2; --i) {
            int left = 0;   
            int right = i - 1; 
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    count += (right - left);
                    right--; 
                } else {
                    left++;
                }
            }
        }
        return count;
    }
};
