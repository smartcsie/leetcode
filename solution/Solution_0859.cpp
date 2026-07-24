/**
 * 題目：859. Buddy Strings
 * 描述：給你兩個字串 s 和 goal。如果可以透過交換 s 中任意兩個字元的位置，
 *       使得結果等於 goal，則返回 true；否則返回 false。
 *       交換字元是指：選擇兩個下標 i 和 j（i != j），然後交換 s[i] 和 s[j]。
 * 
 * 解法思路：
 * 1. 長度檢查：若 s 與 goal 的長度不相等，絕對無法透過交換達成，直接返回 false。
 * 2. 完全相同的情況（s == goal）：
 *    - 如果 s 和 goal 完全一樣，我們必須在 s 中找到「至少有一個重複的字元」可以交換。
 *    - 例如 "aa" 交換兩個 'a' 還是 "aa"，這是合法的；但 "ab" 交換就變成 "ba" 不等於 "ab"。
 *    - 透過 `unordered_set` 檢查 s 的相異字元數是否小於其長度來判斷是否有重複。
 * 3. 不完全相同的情況（s != goal）：
 *    - 走訪字串，記錄所有字元相異的位置索引存入 `diff` 陣列中。
 *    - 完美的親密字串（Buddy Strings）必須剛好有「2 個不同之處」（`diff.size() == 2`），
 *      並且將這兩處交換後，`s` 必須完全等於 `goal`。
 */

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        // 1. 長度不同直接返回 false
        if (s.size() != goal.size()) {
            return false;
        }
        
        // 2. 若兩字串原本就完全相同，必須有重複字元可以互換而不改變外觀
        if (s == goal) {
            std::unordered_set<char> uniqueChars(s.begin(), s.end());
            return uniqueChars.size() < s.size(); // 若相異字元數小於長度，代表有重複
        }
        
        // 3. 若不相同，找出所有字元不同的索引位置
        std::vector<int> diff;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != goal[i]) {
                diff.push_back(i);
            }
        }
        
        // 4. 必須剛好有 2 處不同，且交換後 s 必須等於 goal
        return (diff.size() == 2) && (s[diff[0]] == goal[diff[1]]) && (s[diff[1]] == goal[diff[0]]);
    }
       
};
