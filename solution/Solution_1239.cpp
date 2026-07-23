/**
 * 題目：1239. Maximum Length of a Concatenated String with Unique Characters
 * 描述：給定一個字串陣列 arr，請找出一個字串序列，其串接起來的字串包含唯一字元，
 *       並返回該串接字串的最大可能長度。
 * 
 * 解法思路：
 * 1. 使用 `std::bitset<26>` 將 26 個英文字母的出現狀態壓縮成二進位位元。
 * 2. 宣告 `allBits` 儲存目前所有合法的不重複字元組合狀態（初始為一個空集合）。
 * 3. 走訪 `arr` 中的每一個字串 word：
 *    - 先將 word 轉成 `wordBits`。若 word 本身有重複字元（即 `wordBits.count() < word.size()`），則直接跳過。
 *    - 倒序走訪目前的 `allBits` 陣列，嘗試將當前 word 的 bitset 與已存在的組合進行合併。
 *    - 利用 `(wordBits & bits).any()` 檢查是否有字元衝突（交集）：
 *      - 若有衝突則跳過。
 *      - 若無衝突，則將 `bits | wordBits` 透過 `push_back` 加入 `allBits` 中，並更新最大長度 `ans`。
 * 4. 迴圈結束後返回 `ans`。
 */

class Solution {
public:
    int maxLength(std::vector<std::string>& arr) {
        std::vector<std::bitset<26>> allBits{std::bitset<26>()};
        int ans = 0;
        for (const std::string& word : arr) {
            // 1. 計算當前單字的 bitset
            std::bitset<26> wordBits;
            for (const char& c : word) {
                wordBits.set(c - 'a');
            }
            // 若單字本身內部有重複字元，則不合題意，直接跳過
            if (wordBits.count() < word.size()) {
                continue;
            }
            // 2. 倒序走訪現有的組合，避免在迴圈中因為 push_back 導致重複讀取或崩潰
            int n = allBits.size();
            for (int i = n - 1; i >= 0; --i) {
                std::bitset<26> bits = allBits[i];
                // 若與現有組合有字元交集（衝突），則無法組合
                if ((wordBits & bits).any()) {
                    continue;
                }
                // 無衝突，產生新組合並加入
                allBits.push_back(bits | wordBits);
                // 更新最大長度
                ans = std::max(ans, static_cast<int>(bits.count() + wordBits.count()));
            }
        }
        return ans;
    }
};
