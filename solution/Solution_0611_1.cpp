/**
 * 題目：611. Valid Triangle Number
 * 難度：中等 (Medium)
 * 分類主題：binary-search-find-right-bound
 * 描述：給定一個非負整數陣列 nums，求可以組成三角形的三元組數量
 * （三邊長度需滿足三角不等式：任兩邊之和大於第三邊）。
 *
 * 時間複雜度：O(N²logN)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （固定最小兩邊，對第三邊做找右邊界的二分搜——跟雙指標版固定「最大
 * 邊」的思路相反，這版是固定「最小的兩邊」，反過來找最大能到多大的
 * 第三邊）：
 * 1. 先排序陣列。排序後，只要固定兩個較小的邊 `nums[i]`、`nums[j]`
 *    （`i < j`），三角不等式裡最容易被違反的只有一個條件：
 *    `nums[i] + nums[j] > 第三邊`（因為第三邊是三者中最大的，其他
 *    兩個不等式 `nums[i]+第三邊>nums[j]`、`nums[j]+第三邊>nums[i]`
 *    在第三邊夠大時自動成立，不用額外檢查）。
 * 2. 對固定的 `i`、`j`，要找的是「在 `j` 右邊的範圍裡，第三邊最多能
 *    大到多少，同時還滿足 `nums[i]+nums[j] > 第三邊`」——換句話說，
 *    找出「第一個 >= (nums[i]+nums[j]) 的位置」，這個位置**前面**
 *    （不含自己）的所有位置都是合法的第三邊。
 * 3. 用標準的找右邊界二分搜（`while(lo<hi)`，`nums[mid]>=target` 就
 *    收縮 `hi=mid`，否則 `lo=mid+1`），收斂完 `lo` 就是「第一個
 *    >= target」的位置，答案要往前一格（`lo - 1`）。
 * 4. 從 `j+1` 到 `lo-1` 這段範圍內的所有位置都合法，總共有
 *    `(lo-1) - j` 個，直接累加進答案（不用真的逐一檢查每個位置）。
 * 5. `nums[i]==0` 時直接跳過整個內層迴圈：0 不可能是三角形的一邊
 *    （三邊長度必須是正數），提早剪枝避免浪費計算。
 * 6. 跟雙指標版（O(N²)）的比較：這版多了一個 `log N` 因子，理論上
 *    更慢，但寫法上示範了「固定不同的邊、往不同方向找邊界」的另一種
 *    切入角度——雙指標版是固定最大邊、往內收斂找較小的兩邊；這版是
 *    固定最小兩邊、往外二分搜找最大能到多大的第三邊，兩者是同一個
 *    問題的兩種對稱思路，適合放在一起對照理解。
 */
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n - 2; i++) {
            if(nums[i] == 0) continue;
            for(int j = i + 1; j < n - 1; j++) {
                int target = nums[i] + nums[j];
                int left = j + 1, right = n;
                while(left < right) {
                    int mid = left + (right - left) / 2;
                    if(nums[mid] < target) left = mid + 1;
                    else right = mid;
                }
                count += left - j - 1;
            }
        }
        return count;
    }
};