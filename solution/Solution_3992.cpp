/**
 * 題目：Rearrange String to Avoid Character Pair
 * 描述：調整字串位置，使得特定的字元對 (x, y) 不會出現或符合特定排列。
 * 
 * 解法思路 (雙指標交換)：
 * 1. 使用 left 從左往右尋找目標字元 x。
 * 2. 使用 right 從右往左尋找目標字元 y。
 * 3. 若找到一對符合條件的字元，透過 swap 交換位置，打破不期望的排列結構。
 */

class Solution {
public:
    std::string rearrangeString(std::string s, char x, char y) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            // 從左邊尋找目標字元 x
            while (left < right && s[left] != x) {
                left++;
            }
            // 從右邊尋找目標字元 y
            while (left < right && s[right] != y) {
                right--;
            }
            
            // 若找到一對，進行交換以打破序列
            if (left < right) {
                std::swap(s[left++], s[right--]);
            }
        }
        return s;
    }
};
