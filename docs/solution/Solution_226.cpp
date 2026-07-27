/**
 * 題目：2264. Largest 3-Same-Digit Number in String (字串中最大的 3 位相同數字)
 * 難度：簡單 (Easy)
 * 描述：找出字串中最大的連續 3 個相同數字的字串。
 * * 時間複雜度：O(N) - 遍歷一次字串。
 * 空間複雜度：O(1) - 僅儲存一個字元與一個結果。
 */

class Solution {
public:
    string largestGoodInteger(string num) {
        char maxChar = 0; // 初始化為 0
        // 遍歷到 size - 2，確保 i, i+1, i+2 都在合法範圍
        for(int i = 0 ; i < (int)num.size() - 2; ++i) {
            if(num[i] == num[i + 1] && num[i] == num[i + 2]) {
                maxChar = max(maxChar, num[i]);
            }
        }
        // 若 maxChar 為 0，代表沒找到；否則產生字串
        return maxChar == 0 ? "" : string(3, maxChar);
    }
};
