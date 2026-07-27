/**
 * 題目：2980. Check if Bitwise OR Has Trailing Zeros (檢查位元或運算是否有尾隨零)
 * 難度：簡單 (Easy)
 * 描述：判斷陣列中是否存在兩個數字，其位元或結果最低位為 0。
 * * 時間複雜度：O(N)，N 為陣列長度。
 * 空間複雜度：O(1)。
 * * 優化思路：
 * 1. 邏輯簡化：位元或結果要末位為 0，必須兩個數末位皆為 0，即兩數皆為偶數。
 * 2. 使用位元運算 `(num & 1) == 0` 判斷偶數，比 `% 2` 更符合位元題目背景。
 */

class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int count = 0;
        for(const int& num : nums) {
            if((num & 1) == 0) count++;
            if(count == 2) return true;
        }
        return false;
    }
};
