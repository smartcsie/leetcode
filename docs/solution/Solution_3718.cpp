/**
 * 題目：3718. Smallest Missing Multiple of K (K 的最小缺失倍數)
 * 難度：簡單 (Easy)
 * 描述：在陣列 nums 中找出第一個未出現過的 K 的倍數。
 * * 時間複雜度：O(N + M)，其中 N 為 nums 長度，M 為倍數搜尋範圍。
 * 空間複雜度：O(M)，用於儲存已出現過的倍數標記。
 * * 優化思路：
 * 1. 邊界控制：使用 vector<bool> 替代固定大小陣列，增加程式擴充性。
 * 2. 邏輯優化：直接計算倍數，避免遍歷所有數字。
 */

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> seen(10001, false);
        for(const int& num : nums) {
            if(num % k ==0) seen[num] = true;
        }
        for(int i = 1; ; i++) {
            if(!seen[i * k]) return (i * k);
        }
        return -1;
    }
};
