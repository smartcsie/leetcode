/**
 * 題目：1513. Number of Substrings With Only 1s
 * 描述：給你一個二進位字串 s，返回只包含 '1' 的子字串的個數。
 *       由於答案可能很大，請將其對 10^9 + 7 取模後返回。
 * 
 * 解法思路：
 * 1. 數學規律簡化（連續長度與子字串個數的關係）：
 *    - 如果有一段連續長度為 `k` 的 `1`，它能產生的只包含 `1` 的子字串個數為 `k * (k + 1) / 2`。
 * 2. 邊走訪邊累加（Dynamic Accumulation）：
 *    - 我們不需要等到區段結束才去算總和。當我們依序讀取字元時：
 *      - 若為 `'1'`，連續長度 `count` 加 1。
 *      - 若為 `'0'`，連續長度歸零。
 *    - 每多一個 `'1'`，它能貢獻的子字串數量剛好就是當前的 `count`。
 *    - 因此，在每次迴圈中直接執行 `ans = (ans + count) % MOD` 即可完美等效於分段求和。
 */

class Solution {
public:
    int numSub(std::string s) {
        const int MOD = 1e9 + 7;
        int ans = 0;
        int count = 0;
        
        for (char c : s) {
            // 若為 '1' 則長度加 1，否則重置為 0
            count = (c == '1') ? count + 1 : 0;
            
            // 當前連續長度即為新增的子字串貢獻量
            ans = (ans + count) % MOD;
        }
        
        return ans;
    }
};
