/**
 * 題目：744. Find Smallest Letter Greater Than Target (尋找比目標字母大的最小字母)
 * 難度：簡單 (Easy)
 * 描述：在有序字元陣列中找第一個大於 target 的字元，若無則回傳陣列第一個字元。
 *
 * 時間複雜度：O(logN)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 使用 `std::upper_bound` 找出第一個「大於」target 的位置。
 * 若 `it` 指向陣列結尾，代表無符合條件字元，返回首元素；
 * 否則直接返回 `it` 指向的字元。
 */

#include <vector>
#include <algorithm>

class Solution {
public:
    char nextGreatestLetter(std::vector<char>& letters, char target) {
        auto next = upper_bound(letters.begin(), letters.end(), target);
        return next == letters.end() ? letters[0] : *next;
    }
};
