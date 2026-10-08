/**
 * 題目：1018. Binary Prefix Divisible By 5
 * 難度：簡單 (Easy)
 * 描述：判斷二進位陣列的每個前綴是否能被 5 整除。
 * 優化重點：
 * 1. 同餘性質：在每一步計算後直接對 5 取模，防止數值過大。
 * 2. 避免冗餘運算：sum 已經經過 % 5 處理，判斷時直接比較 `sum == 0` 即可。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    std::vector<bool> prefixesDivBy5(std::vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans(n);
        int num = 0;
        for(int i = 0; i < n; i++) {
            num = ((num << 1) + nums[i]) % 5;
            ans[i] = (num % 5) == 0;
        }
        return ans;
    }
};
