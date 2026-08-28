/**
 * 題目：3084. Count Substrings Starting and Ending with Given Character
 * 難度：簡單 (Easy)
 * 描述：給定一個字串 s 和一個字元 c，計算有多少個子字串的起點和終點都是 c。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （數學貢獻法）：
 * 1. 遍歷字串，用 count 記錄到目前為止遇到的 c 的個數。
 * 2. 每遇到一個新的 c（假設是第 n 個），它可以和前面所有的 c 組成子字串，
 *    加上它自己單獨成一個子字串，共新增 count 個子字串。
 * 3. 累加每次的貢獻到 ans。
 *
 * 範例：s = "abcbc", c = 'b'
 *   第 1 個 b（index 1）：count=1，ans += 1 → ans=1  （"b"）
 *   第 2 個 b（index 3）：count=2，ans += 2 → ans=3  （"b", "bcb", "b"）
 */

class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long count = 0;
        long long ans = 0;
        for(const char& x : s) {
            if(x == c) {
                count++;
                ans += count;
            }
        }
        return ans;
    }
};