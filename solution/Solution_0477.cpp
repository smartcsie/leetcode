/**
 * 題目：477. Total Hamming Distance
 * 描述：兩個整數的漢明距離指的是這兩個數字二進位表示形式中不同的位元數。
 *       給你一個整數陣列 nums，請計算陣列中任意兩個數之間漢明距離的總和。
 * 
 * 解法思路：
 * 1. 漢明距離的核心概念是「逐個位元獨立計算」。各個位元之間互不干涉，因此我們可以把每一位分開來看。
 * 2. 遍歷整數的 31 個位元（從第 0 個 bit 到第 30 個 bit）。
 * 3. 對於每一個 bit：
 *    - 統計陣列中有多少個數字在該 bit 上是 1（記為 `ones`）。
 *    - 那麼在該 bit 上是 0 的數字個數就是 `zeros = n - ones`。
 *    - 根據乘法原理，在該 bit 上會產生不同結果（0 和 1 配對）的組合數為 `ones * zeros`。
 * 4. 將該位元產生的不同對數乘以該位元的權重（`1 << bit`），並累加到總和 `sum` 中。
 * 5. 迴圈結束後返回 `sum`。
 */

class Solution {
public:
    int totalHammingDistance(std::vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        // 遍歷 32 位整數的每一個 bit（根據題意最大到 30 個 bit 左右）
        for (int bit = 0; bit < 31; ++bit) {
            int ones = 0;
            // 統計當前 bit 為 1 的數字個數
            for (int num : nums) {
                // 檢查 num 的第 bit 位是否為 1
                ones += (num >> bit) & 1;
            }
            int zeros = n - ones;
            int pairsOne = ones * zeros; // 該位元產生漢明距離貢獻的數對總數
            sum += pairsOne; // 加上該位元帶來的總距離貢獻
        }
        return sum;
    }
};
