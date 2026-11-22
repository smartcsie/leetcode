// 題目：1295. Find Numbers with Even Number of Digits
// 難度：Easy
// 時間複雜度：O(n · d)，n = 陣列長度，d = 每個數字的位數（最多 6，視為 O(n)）
// 空間複雜度：O(1)
// 分類主題：array / math
// 技巧：不斷除以 10 計算位數，用 digits & 1 判斷奇偶

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;   // 位數為偶數的數字個數
        for(const int& x : nums) {
            int n = x;       // 複製一份來除，不改到原陣列
            int digits = 0;  // x 的位數

            // 每除以 10 就去掉一位，除到 0 為止，除了幾次就有幾位
            // 例：x = 345 -> 34 -> 3 -> 0，共 3 次，digits = 3
            // 題目保證 1 <= nums[i] <= 10^5，沒有 0，所以不需要特判 0 的位數
            while(n > 0) {
                digits++;
                n /= 10;
            }

            // digits & 1：最低位是 1 代表奇數，是 0 代表偶數
            // 位數是偶數就計入
            if(!(digits & 1)) count++;
        }
        return count;
    }
};