/**
 * 題目：3120. Count the Number of Special Characters I
 * 難度：簡單 (Easy)
 * 描述：計算字串中同時出現大小寫形式的字母數量。
 * * 優化重點：
 * 1. 位元遮罩 (Bitmask)：使用 int 作為 26 位元陣列，紀錄 'a'-'z' 與 'A'-'Z' 的出現狀態。
 * 2. 空間效率：僅用兩個整數變數，實現 O(1) 的輔助空間。
 * 3. 狀態合併：透過 `lower & upper` 運算，直接找出同時存在的位元。
 */

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lower = 0;
        int upper = 0;
        for(char c : word) {
            if(islower(c)) lower |= 1 << (c-'a');
            if(isupper(c)) upper |= 1 << (c-'A');
        }
        return __builtin_popcount(lower & upper);
    }
};
