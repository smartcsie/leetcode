/**
 * 題目：3340. Check Balanced String (檢查平衡字串)
 * 難度：簡單 (Easy)
 * 描述：判斷字串中偶數索引處的數字之和是否等於奇數索引處的數字之和。
 * * 時間複雜度：O(N) - 遍歷一次字串。
 * 空間複雜度：O(1) - 僅使用整數累加器。
 * * 優化思路：
 * 1. 雙累加器：使用兩個變數分別維護奇偶索引的和。
 * 2. 單次循環：在迴圈中一次處理兩個相鄰的字元，減少循環次數。
 */

class Solution {
public:
    bool isBalanced(string num) {
        int oddSum = 0;
        int evenSum = 0;
        for(int i = 0; i < num.size(); i++) {
            int digit = num[i] - '0';
           if(i % 2 == 1)  oddSum += digit;
           else  evenSum += digit;
        }
        return oddSum == evenSum;
    }
};
