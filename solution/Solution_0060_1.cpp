/**
 * 題目：60. Permutation Sequence
 * 難度：困難 (Hard)
 * 分類主題：backtracking-permutation
 * 技巧：next_permutation
 * 描述：給定 n，把 1 到 n 組成的所有排列按字典序排好，求第 k 個排列
 * （k 從 1 開始算）。
 *
 * 時間複雜度：O(N × K)，最壞情況 O(N × N!)（N 最大到 9，N! 頂多
 * 362880，題目限制保證這個暴力解跑得動）
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （暴力窮舉版，用 next_permutation 一個一個往後走，數到第 k 個就
 * 停下來——這題其實有更快的 O(N²) 數學解法，利用階乘進位制直接算出
 * 每一位該放哪個數字，不用真的窮舉；這版是最直觀但效率較差的寫法，
 * 因為題目給的 n 上限只到 9，暴力法在這個範圍內完全跑得動）：
 * 1. nums 初始化成 1 到 n 遞增排列，這是字典序最小的排列，也就是
 *    第 1 個排列——這是 `next_permutation` 能窮舉「全部」排列的
 *    必要起點（跟之前 arr 沒排序就用 `next_permutation` 會漏掉排列
 *    是同一個道理）。
 * 2. do-while 迴圈每一輪代表往後走到「下一個」排列，每走一輪 k 就
 *    減 1；當 k 減到 0，代表目前這個排列剛好是題目要的第 k 個
 *    （因為從第 1 個排列開始算起，走了 k-1 次 `next_permutation`
 *    之後，就會停在第 k 個排列上）。
 * 3. k 歸零時，把目前的 nums 陣列轉成字串（每個數字加上 `'0'` 轉成
 *    對應字元），存進 ans。
 * 4. 因為題目保證 k 一定合法（不超過 n! 種排列總數），迴圈一定會在
 *    某一輪碰到 k == 0 為止，不用擔心 `next_permutation` 繞完一圈
 *    回到最小排列還找不到答案的情況。
 */
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        for(int x = 1; x <= n; x++) {
            nums[x - 1] = x;
        }
        string ans;
        ans.reserve(n);
        do {
            k--;
            if(k == 0) {
                for(int i = 0; i < n; i++) ans.push_back(nums[i] + '0');
            }
        } while(next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};