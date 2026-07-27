/**
 * 題目：389. Find the Difference (找出不同的字元)
 * 難度：簡單 (Easy)
 * 描述：字串 t 是由字串 s 打亂後再隨機插入一個字母組成，找出該字母。
 * * 時間複雜度：O(N)，僅需遍歷兩字串各一次。
 * 空間複雜度：O(1)，僅需一個變數儲存 XOR 結果。
 * * 優化思路：
 * 1. XOR 運算：無需額外記憶體空間儲存字元頻率，利用位元運算的交換律與結合律。
 * 2. 效能提升：減少了陣列索引存取與邏輯判斷，在 CPU 層級執行速度最快。
 */

class Solution {
public:
    char findTheDifference(string s, string t) {
        char miss = 0;
        for(const char& c : s) miss ^= c;
        for(const char& c : t) miss ^= c;
        return miss;
    }
};
