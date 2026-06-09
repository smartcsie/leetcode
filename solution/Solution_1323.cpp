/**
 * 題目：1323. Maximum 69 Number (最大 69 數字)
 * 難度：簡單 (Easy)
 * 描述：給你一個僅由 6 和 9 組成的正整數，你最多可以改變一位數字（6 變 9，或 9 變 6），求能得到的最大數字。
 * * 時間複雜度：O(D)，D 為數字的位數。
 * 空間複雜度：O(1) - 不使用額外字串儲存，僅使用整數變數。
 * * 優化思路：
 * 1. 數學法：找到最高位的 6 並加上 3000... (對應的位數差)，比字串轉換更省記憶體。
 */

class Solution {
public:
    int maximum69Number (int num) {
        string str = to_string(num);
        for(char& c : str) {
            if(c == '6')  {
                c='9';
                break;
            }
        }
        return stoi(str);
    }
};
