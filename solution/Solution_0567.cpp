/**
 * 題目：567. Permutation in String (字串的排列)
 * 難度：中等 (Medium)
 * 描述：判斷 s2 是否包含 s1 的排列。
 * * 時間複雜度：O(L2) - 遍歷 s2 一次。
 * 空間複雜度：O(1) - 使用長度為 26 的固定頻率陣列。
 * * 優化思路：
 * 1. 滑動視窗：維護一個長度為 n1 的滑動視窗。
 * 2. 頻率陣列：利用陣列儲存字符計數，避免生成 s1 的所有排列。
 */

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if(n1 > n2) return false;
        vector<int> count1(26, 0), count2(26, 0);

        for(int i = 0; i < n1;i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        } 

        for(int i = 0; i < n2 - n1;i++) {
            if(count1 == count2) return true;
            count2[s2[i] - 'a']--;
            count2[s2[i+n1] - 'a']++;
        } 

        return count1 == count2;
    }
};
