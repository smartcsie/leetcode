/**
 * 題目：1018. Binary Prefix Divisible By 5
 * 難度：簡單 (Easy)
 * 描述：判斷二進位陣列的每個前綴是否能被 5 整除。
 * * 優化重點：
 * 1. 同餘性質：在每一步計算後直接對 5 取模，防止數值過大。
 * 2. 避免冗餘運算：sum 已經經過 % 5 處理，判斷時直接比較 `sum == 0` 即可。
 */

class Solution {
public:
    std::vector<bool> prefixesDivBy5(std::vector<int>& nums) {
        int sum = 0;
        std::vector<bool> divisible;
        divisible.reserve(nums.size());
        
        for (const int num : nums) {
            sum = ((sum << 1) + num) % 5;
            divisible.push_back(sum == 0);
        }
        
        return divisible;
    }
};
