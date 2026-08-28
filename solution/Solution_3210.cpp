/**
 * 題目：3210. Find the Encrypted String
 * 難度：簡單 (Easy)
 * 描述：將字串每個位置的字元替換為向右循環位移 k 位的字元。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 1. 為了處理 k 可能大於字串長度 n 的情況，先執行 `k %= n`。
 * 2. 建立一個長度與原字串相同的結果字串 t。
 * 3. 對於每個索引 i，目標位置為 `(i + k) % n`，將該處字元填入 t[i]。
 */

class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.size();
        string ans;
        k %= n;
        for(int i = 0; i < n; i++) {
            ans.push_back(s[(i + k) % n]);
        }
        return ans;
    }
};
