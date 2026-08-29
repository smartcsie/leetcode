/**
 * 題目：2521. Distinct Prime Factors of Product of Array (陣列積的相異質因數)
 * 難度：中等 (Medium)
 * 描述：計算陣列中所有數字乘積的相異質因數數量。
 *
 * 時間複雜度：O(N*sqrt(M)
 * 空間複雜度：O(K)
 *
 * 解法思路：
 * 1. 使用 `std::unordered_set` 處理去重。
 * 2. 針對質因數分解邏輯進行簡化，提升執行速度。
 */

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> fators;
        for(int num : nums) {
            for(int p = 2; p * p <= num; p++) {
                if(!(num % p )) {
                    fators.insert(p);
                    while(!(num % p)) num /= p;
                }
                
            }
            if(num > 1) fators.insert(num);
        }
        return fators.size();
    }
};
