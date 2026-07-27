/**
 * 題目：3325. Count Substrings With K-Frequency Characters I
 * 難度：待補充
 * 描述：給你一個字串 s 和一個整數 k，請你返回 s 中包含至少一個字元出現頻率大於或等於 k 次的子字串數量。
 *
 * 時間複雜度：O(N) - 滑動視窗，固定 26 個字母計數陣列。
 * 空間複雜度：O(1) - 固定大小計數陣列。
 *
 * 解法思路：
 * （滑動視窗法 Sliding Window）：
 * 1. 視窗擴張與條件滿足：
 * - 使用右指標 `right` 逐一將字元納入視窗中，並更新字元頻率統計陣列 `counts`。
 * - 當某個字元的頻率達到 `k`（`counts[s[right] - 'a'] >= k`）時，代表以當前 `right` 為結尾、且包含此狀態的視窗已經「符合條件」。
 * 2. 視窗收縮與計數加總：
 * - 此時，如果我們將左指標 `left` 向右移動，所有以當前 `right` 為結尾、起點小於等於 `left` 的子字串（總共 `left` 個）也都必然符合條件。
 * - 因此，每次當視窗滿足條件時，我們透過 `ans += left` 一次性將這些合法的子字串數量累加進答案，並持續收縮 `left` 直到條件剛好不滿足為止。
 */

class Solution {
public:
    int numberOfSubstrings(std::string s, int k) {
        int n = s.size();
        vector<int> counts(26, 0); // 記錄 26 個英文字母的出現頻率
        int left = 0;
        int ans = 0;
        for (int right = 0; right < n; right++) {
            // 擴張視窗：將當前字元納入統計
            counts[s[right] - 'a']++;
            // 當某字元頻率達到 k 時，收縮左指標以找出所有以 right 結尾的合法子字串起點
            while (counts[s[right] - 'a'] >= k) {
                counts[s[left++] - 'a']--;
            }
            // 累加此時所有以 right 結尾且合法的子字串數量
            ans += left;
        }
        return ans;
    }
};
