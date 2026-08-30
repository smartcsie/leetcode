/**
 * 題目：318. Maximum Product of Word Lengths
 * 難度：待補充
 * 描述：給你一個字串陣列 words，請你計算兩字串 word[i] 和 word[j] 不包含任何相同字元時，
 * 其長度乘積的最大值（length(word[i]) * length(word[j])）。如果找不到這樣的兩個字元不重複的字串，返回 0。
 *
 * 時間複雜度：O(N^2+N*L)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （位元遮罩與位元運算 Bitmask & Bitwise Operation）：
 * 1. 字元狀態壓縮（Bitmask）：
 * - 由於題目只包含小寫英文字母（26個），我們可以用一個 32 位元的整數（`int`）來作為位元遮罩（Bitmask）。
 * - 利用 `1 << (c - 'a')` 將字串中出現過的字元對應到整數的特定位元上（例如 'a' 對應第 0 位，'b' 對應第 1 位）。
 * 2. 快速不重複檢查：
 * - 兩個字串如果沒有共同字元，代表它們的位元遮罩進行「位元及（AND）」運算後的結果會是 0（即 `(masks[i] & masks[j]) == 0`）。
 * 3. 遍歷配對與最大值更新：
 * - 預先計算好所有字串的 `masks` 後，透過巢狀迴圈兩兩配對，若符合無交集條件，則更新最大長度乘積。
 */


public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> masks(n ,0);
        vector<int> sizes(n ,0);
        for(int i = 0; i < n; i++) {
            for(const char& c : words[i]) {
                masks[i] |= 1 << (c - 'a');
                sizes[i] = static_cast<int>(words[i].size());
            }
        }
        int ans = 0;
        for(int i = 0; i < n-1; i++) {
            for(int j = i + 1; j < n; j++) {
                if(!(masks[i] & masks[j])) ans = max(ans, sizes[i] * sizes[j]);
            }
        }
        return ans;
    }
};
