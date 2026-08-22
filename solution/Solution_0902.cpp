/**
 * 題目：902. Numbers At Most N Given Digit Set
 * 難度：困難 (Hard)
 * 描述：給定一組只包含單一數字的字串 digits（例如 ["1","3","5"]），
 * 可以重複使用這些數字組成新的正整數，求小於等於 n 的正整數總共能組成
 * 幾個。
 *
 * 時間複雜度：O(len(N) * len(digits))
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （逐位比對，Digit DP 的典型「按位數分段計算」套路）：
 * 1. 把 n 轉成字串 s，len 是 n 的位數。
 * 2. 先算「位數比 n 少」的情況：位數是 1 到 len-1 的數字，每一位都能
 *    自由從 digits 裡選（因為位數比 n 少，一定比 n 小），總共有
 *    k^1 + k^2 + ... + k^(len-1) 種（k 是 digits 的種類數）。
 * 3. 再算「位數跟 n 一樣」的情況，逐位比對 s 的每一位 s[i]：
 *    - 對 digits 裡每個字元 d：如果 d < s[i]，代表這一位選 d 的話，
 *      後面剩下的位數可以隨便選（因為這一位已經比 n 小了），貢獻
 *      k^(len-i-1) 種。如果 d == s[i]，記錄「這一位可以跟 n 打平」，
 *      繼續往下一位比對（matched = true）。
 *    - 如果這一位在 digits 裡完全找不到 <= s[i] 的字元可以打平或更小
 *      （matched 是 false），代表沒辦法再往後湊出等於或超過 n 的情況了，
 *      直接回傳目前的 total（後面的位數不用再看）。
 * 4. 如果一路比對到最後一位都能打平（每一位都在 digits 裡找得到），
 *    代表 n 本身可以用 digits 完整拼出來，額外 +1。
 */
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int k = digits.size();
        int len = s.size();
        long long total = 0;
        long long power = 1;
        for (int i = 1; i < len; ++i) {
            power *= k;
            total += power;
        }
        bool matched = false;
        for (int i = 0; i < len; ++i) {
            matched = false;
            long long perm = 1;
            for (int j = 0; j < len - i - 1; ++j) perm *= k;
            for (auto& d : digits) {
                if (d[0] < s[i]) {
                    total += perm;
                } else if (d[0] == s[i]) {
                    matched = true;
                    break;
                }
            }
            if (!matched) return (int)total;
        }
        if (matched) total += 1;
        return (int)total;
    }
};
