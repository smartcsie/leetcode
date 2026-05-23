/**
 * 題目：58. Length of Last Word (最後一個單字的長度)
 * 難度：簡單 (Easy)
 * 描述：給你一個字串 s，由單字和空格組成，返回字串中最後一個單字的長度。
 * 
 * 時間複雜度：O(n) - 最壞情況下遍歷整個字串一次。
 * 空間複雜度：O(1) - 僅使用整數變數，不需要額外空間。
 * 
 * 解法思路 (從後往前)：
 * 1. 設置指針從字串尾端開始。
 * 2. 第一個 while 迴圈：跳過末尾的所有空格 (處理類似 "Hello World  " 的情況)。
 * 3. 第二個 while 迴圈：計算從非空格字元開始到下一個空格出現前的字元數。
 */

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int right = s.size() - 1;
        
        // 1. 跳過末尾的空格
        while (right >= 0 && s[right] == ' ') {
            right--;
        }
        
        // 2. 計算最後一個單字的長度
        while (right >= 0 && s[right] != ' ') {
            right--;
            length++;
        }
        
        return length;
    }
};
