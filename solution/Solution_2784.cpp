/**
 * 題目：2784. Check if Array is Good (檢查陣列是否有效)
 * 難度：簡單 (Easy)
 * 描述：給定一個整數陣列 nums。如果該陣列是 [1, 2, ..., n-1, n, n] 的一個排列，則稱其為「好陣列」。
 * 也就是說，如果最大值為 n，則陣列長度必須為 n + 1，且 1 到 n-1 各出現一次，n 出現兩次。
 *
 * 時間複雜度：O(N) - 遍歷一次陣列找出最大值，再遍歷一次統計次數。
 * 空間複雜度：O(N) - 使用頻率陣列 (Frequency Array) 來儲存每個數字出現的次數。
 */

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(201, 0);
        for(const int& x : nums) counts[x]++;
        for(int i = 1; i < n -1 ; i++) {
            if(counts[i] != 1) return false;
        }
        return counts[n - 1] == 2;
    }
};
