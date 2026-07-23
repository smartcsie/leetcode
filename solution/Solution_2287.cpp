/**
 * 題目：2287. Rearrange Characters to Make Target String
 * 描述：給你兩個字串 s 和 target。你可以從 s 中取出字元並重新排列它們，
 *       使其形成多個 target 副本。求出你可以形成的 target 最大副本數。
 * 
 * 解法思路：
 * 1. 宣告兩個大小為 26 的計數陣列 `count` 與 `countS`，分別用來記錄 target 和 s 中各字母的頻率。
 * 2. 走訪 target，將每個字元的所需數量記錄於 `count`。
 * 3. 走訪 s，將每個字元的擁有數量記錄於 `countS`。
 * 4. 初始化 ans 為一個足夠大的數（例如 1000，因為題目測資 s 長度通常小於等於 100）。
 * 5. 針對 target 中有出現的每個字元（`count[i] > 0`）：
 *    - 計算 s 擁有的數量可以支撐幾份該字母：`countS[i] / count[i]`。
 *    - 用 `ans` 記錄所有字母中的最小值（即木桶效應的「短板瓶頸」）。
 * 6. 返回 ans 即為最多可拼出的 target 數量。
 */

class Solution {
public:
    int rearrangeCharacters(std::string s, std::string target) {
        std::vector<int> count(26, 0);
        std::vector<int> countS(26, 0);
        // 統計 target 中每個字元的所需頻率
        for (const char& c : target) {
            count[c - 'a']++;
        }
        // 統計 s 中每個字元的現有頻率
        for (const char& c : s) {
            countS[c - 'a']++;
        }
        int ans = 1000; // 可以設定為比最大可能份數更大的初始值
        // 檢查 target 中每個必須字元的供應瓶頸
        for (int i = 0; i < 26; ++i) {
            if (count[i] > 0) {
                ans = std::min(ans, countS[i] / count[i]);
            }
        }
        return ans;
    }
};
