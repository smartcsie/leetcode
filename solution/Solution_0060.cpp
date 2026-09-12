/**
 * 題目：60. Permutation Sequence
 * 難度：困難 (Hard)
 * 分類主題：backtracking-permutation
 * 技巧：iota, factorial number system
 * 描述：給定 n，把 1 到 n 組成的所有排列按字典序排好，求第 k 個排列。
 *
 * 時間複雜度：O(N²)（`erase` 每次是 O(N)，跑 N 輪）
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （階乘進位制，Factorial Number System——不用真的窮舉排列，直接用
 * 數學計算「這一位該放哪個數字」，比 next_permutation 暴力版快很多）：
 * 1. **關鍵觀察**：n 個數字的所有排列，固定最左邊那一位之後，剩下
 *    n-1 個數字能排出 `(n-1)!` 種排列。也就是說，把所有排列依照
 *    「最左邊那一位是誰」分組，每一組剛好有 `(n-1)!` 個排列、按組
 *    排好順序。
 * 2. `k / (n-1)!` 的商，就是「第 k 個排列的最左邊那一位，該選剩餘
 *    候選裡的第幾個」；餘數則是「在這一組裡面，是第幾個排列」，
 *    可以用同樣的邏輯繼續往下一位遞迴判斷。
 * 3. `remaining` 從 n 倒數到 1，代表「目前還剩幾個候選數字沒決定」；
 *    `blockSize = factorial[remaining-1]` 就是「固定這一位之後，
 *    剩下的數字能排出幾種排列」。
 * 4. `pos = k / blockSize` 算出這一位該選第幾個候選，取出
 *    `nums[pos]` 接進答案，並把它從候選清單裡移除（`erase`，這樣
 *    候選清單會自動縮小，下一輪就是「剩下的數字」）。
 * 5. `k %= blockSize` 把 k 更新成「扣掉這一位已經決定的整數塊之後，
 *    剩下的餘數」，留給後面幾位繼續判斷。
 * 6. `k--` 是因為題目的 k 是 1-indexed，換算成陣列索引邏輯要先減 1。
 */
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);

        vector<int> factorial(n);
        factorial[0] = 1;
        for (int i = 1; i < n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }

        string res;
        k--;

        for (int remaining = n; remaining >= 1; --remaining) {
            int blockSize = factorial[remaining - 1];
            int pos = k / blockSize;

            res += to_string(nums[pos]);
            nums.erase(nums.begin() + pos);

            k %= blockSize;
        }
        return res;
    }
};