/**
 * 題目：3151. Special Array I (特殊陣列 I)
 * 難度：簡單 (Easy)
 * 描述：如果陣列中每一對相鄰元素的奇偶性皆不同，則稱為特殊陣列。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size() == 1) return true;
        bool odd = nums[0] & 1;
        for(int i = 1; i < nums.size(); i++) {
            odd = !odd;
            if((nums[i] & 1) != odd) return false;
        }
        return true;
    }
};
