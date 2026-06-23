/**
 * 題目：3663. Find The Least Frequent Digit (找出出現頻率最低的數位)
 * 難度：簡單 (Easy)
 * 描述：在正整數 n 的所有數位中，找出出現頻率最低且出現過的數字。
 * * 時間複雜度：O(log N)，處理數字的位數。
 * 空間複雜度：O(1)，僅使用大小為 10 的陣列。
 * * 優化思路：
 * 1. 簡化狀態追蹤：移除 pair，使用兩個純整數變數追蹤最小頻率及其對應數位。
 * 2. 處理邊界：明確處理 n = 0 的情況。
 */

class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int> counts(10, 0);
        int temp = n;
        while(temp > 0) {
            counts[temp % 10]++;
            temp /= 10;
        }
        int minDigit = -1;
        int minFreq = INT_MAX;
        for(int i = 0; i < 10; i++) {
            if(counts[i] > 0 && counts[i] < minFreq) {
                minFreq = counts[i];
                minDigit = i;
            }
        }
        return minDigit;
    }
};
