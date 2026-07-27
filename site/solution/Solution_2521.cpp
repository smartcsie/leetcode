/**
 * 題目：2521. Distinct Prime Factors of Product of Array (陣列積的相異質因數)
 * 難度：中等 (Medium)
 * 描述：計算陣列中所有數字乘積的相異質因數數量。
 * * 時間複雜度：O(N * sqrt(M))，N 為陣列長度，M 為陣列中的最大值。
 * 空間複雜度：O(K)，K 為相異質因數的數量。
 * * 優化思路：
 * 1. 使用 `std::unordered_set` 處理去重。
 * 2. 針對質因數分解邏輯進行簡化，提升執行速度。
 */

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> factors;
        for(int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            if (temp % 2 == 0) {
                factors.insert(2);
                while(temp % 2 == 0) temp /= 2;
            }
            for(int j = 3; j * j <= temp; j+=2) {
                if(temp % j == 0) {
                    factors.insert(j);
                    while(temp % j == 0) temp /= j;
                }
            }
            if (temp > 1) factors.insert(temp); 
        }
        return static_cast<int>(factors.size());
    }
};
