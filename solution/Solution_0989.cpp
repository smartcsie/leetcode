/**
 * 題目：989. Add to Array-Form of Integer
 * 難度：簡單 (Easy)
 * 描述：將陣列形式表示的整數 num 與整數 k 相加，回傳相加後的陣列形式結果。
 *
 * 核心概念：
 * - 從陣列最低位開始，逐位與 k 相加並處理進位。
 * - 利用 k 同時承載「待加數值」與「進位」兩種角色。
 * - 迴圈持續到陣列位數耗盡且 k 歸零為止。
 * - 最後反轉結果陣列，恢復高位在前的正確順序。
 */
class Solution {
public:
    vector addToArrayForm(vector& num, int k) {
        int n = num.size();
        int i = n - 1;
        vector res;
        while(i >= 0 || k > 0) {
            if(i >= 0) k += num[i--];
            res.push_back(k % 10);
            k /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
