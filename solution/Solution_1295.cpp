/**
 * 題目：1295. Find Numbers with Even Number of Digits (統計位數為偶數的數字)
 * 難度：簡單 (Easy)
 * 描述：統計陣列中位數為偶數的數字個數。
 * * 時間複雜度：O(N) - 遍歷陣列一次。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 將數字轉為字串需要 O(D) 的空間與時間 (D 為位數)。
 * 利用數學公式 `floor(log10(num)) + 1` 可以在 O(1) 時間內直接計算位數，
 * 避免記憶體分配開銷。
 */

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (const int& num : nums) {
            // log10(num) + 1 即為數字的位數
            // 例如 log10(100) = 2, 位數為 2+1 = 3
            // 例如 log10(1234) = 3, 位數為 3+1 = 4
            if ((static_cast<int>(log10(num)) + 1) % 2 == 0) {
                count++;
            }
        }
        return count;
    }
};
