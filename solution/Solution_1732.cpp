/**
 * 題目：1732. Find the Highest Altitude
 * 難度：簡單 (Easy)
 * 描述：給你一個海拔變化陣列 gain，起點為 0，計算並回傳最高海拔。
 *
 * 時間複雜度：O(N) - 單次遍歷，追蹤前綴和最大值。
 * 空間複雜度：O(1) - 僅使用常數空間。
 *
 * 解法思路：
 * 1. 初始化 `maxAltitude` 為 0（因為起點為 0）。
 * 2. 初始化 `currentAltitude` 為 0。
 * 3. 遍歷 gain 陣列，累加每個變化量，並在每次更新時維護最大值。
 */

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max = 0;
        int sum = 0;
        for(const int& num : gain) {
            sum += num;
            max = std::max(max, sum);
        }
        return max;
    }
};
