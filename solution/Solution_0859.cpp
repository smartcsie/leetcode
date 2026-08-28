/**
 * 題目：859. Buddy Strings
 * 難度：待補充
 * 描述：給你兩個字串 s 和 goal。如果可以透過交換 s 中任意兩個字元的位置，
 * 使得結果等於 goal，則返回 true；否則返回 false。
 * 交換字元是指：選擇兩個下標 i 和 j（i != j），然後交換 s[i] 和 s[j]。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 長度檢查：若 s 與 goal 的長度不相等，絕對無法透過交換達成，直接返回 false。
 * 2. 完全相同的情況（s == goal）：
 * - 如果 s 和 goal 完全一樣，我們必須在 s 中找到「至少有一個重複的字元」可以交換。
 * - 例如 "aa" 交換兩個 'a' 還是 "aa"，這是合法的；但 "ab" 交換就變成 "ba" 不等於 "ab"。
 * - 透過 `unordered_set` 檢查 s 的相異字元數是否小於其長度來判斷是否有重複。
 * 3. 不完全相同的情況（s != goal）：
 * - 走訪字串，記錄所有字元相異的位置索引存入 `diff` 陣列中。
 * - 完美的親密字串（Buddy Strings）必須剛好有「2 個不同之處」（`diff.size() == 2`），
 * 並且將這兩處交換後，`s` 必須完全等於 `goal`。
 */

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        string& t = goal;
        if(s.size() != t.size()) return false;;
        unordered_set<char> uniqueSet(s.begin(), s.end());
        if(s == t) return uniqueSet.size() < s.size();
        int left = 0;
        int right = s.size() - 1;
        while(left < right) {
            while(left < right && s[left] == t[left]) left++;
            while(left < right && s[right] == t[right]) right--;
            if(left < right) {
                swap(s[left],s[right]);
                return s == t;
            }
        }
        return false;
    }
       
};
