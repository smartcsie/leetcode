/**
 * 題目：1608. Special Array With X Elements Greater Than or Equal X
 * 難度：簡單 (Easy)
 * 描述：給定非負整數陣列 nums。若存在一個數字 x，使得 nums 中
 *       恰好有 x 個元素大於或等於 x，則 nums 是特殊陣列，回傳該 x；
 *       否則回傳 -1。題目保證若 x 存在則唯一，且 x 不必出現在 nums 裡。
 *
 * 分類主題：array-suffix-sum
 * 技巧：計數陣列, 後綴和, 值域固定用 array
 *
 * 時間複雜度：O(N + V)，V = 1000 為值域上界
 * 空間複雜度：O(V)
 *
 * 解法思路：計數 + 後綴和
 * 1. 值域只有 0 ~ 1000，先用 counts[v] 統計每個值出現幾次。
 * 2. 把 counts 轉成後綴和：counts[i] += counts[i + 1]，
 *    轉完後 counts[i] 就是「nums 中大於或等於 i 的元素個數」。
 * 3. 從 0 到 1000 掃描，第一個滿足 counts[i] == i 的 i 就是答案；
 *    都不滿足則回傳 -1。
 * 4. x = 0 不會成立：nums 至少有 1 個元素，counts[0] = n >= 1，
 *    所以不需要特判。
 */
class Solution {
public:
    int specialArray(vector<int>& nums) {
        array<int, 1001> counts = {};  // counts[v]：值為 v 的元素個數，之後轉成後綴和

        // 統計每個值出現的次數
        for (const int& x : nums) counts[x]++;

        // 轉成後綴和：counts[i] = 大於或等於 i 的元素個數
        // counts[1000] 本身已是後綴和，所以從 999 開始往前累加
        for (int i = 999; i >= 0; i--) counts[i] += counts[i + 1];

        // 找到「恰好有 i 個元素大於或等於 i」的 i
        for (int i = 0; i <= 1000; i++) {
            if (counts[i] == i) return i;
        }
        return -1;
    }
};