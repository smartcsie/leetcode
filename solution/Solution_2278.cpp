/**
 * 題目：2278. Percentage of Letter in String
 * 描述：給你一個字串 s 和一個字元 letter。返回在 s 中等於 letter 的字元所佔的百分比，
 *       向下取整到最接近的整數。
 * 
 * 解法思路：
 * 1. 計算頻率：
 *    - 使用 `<algorithm>` 中的 `std::count` 快速統計字元 `letter` 在字串 `s` 中出現的總次數。
 * 2. 算術運算與向下取整：
 *    - 百分比計算公式為：`(count * 100) / s.size()`。
 *    - 為了避免整數除法造成精確度遺失，必須**先乘 100 再除以總長度**。
 *    - 由於 C++ 中整數相除會自動截斷小數點（向下取整），剛好符合題目要求的向下取整規則。
 */

class Solution {
public:
    int percentageLetter(std::string s, char letter) {
        // 先乘 100 再除以長度，利用整數除法自動向下取整
        return std::count(s.begin(), s.end(), letter) * 100 / s.size();
    }
};
