/**
 * 題目：2124. Check if All A's Appears Before All B's (檢查所有 A 是否都在 B 之前)
 * 難度：簡單 (Easy)
 * 描述：如果字串中所有 'a' 都出現在所有 'b' 之前，回傳 true。
 * * 時間複雜度：O(N) - 只需遍歷字串一次。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 只要遇到 'b' 後面又出現了 'a'，就代表不符合規則。
 */

class Solution {
public:
    bool checkString(string s) {
        return is_sorted(s.begin(), s.end());
    }
};


/*
class Solution {
public:
    bool checkString(string s) {
        int aIdx = (s.rfind('a') == std::string::npos) ? -1 : static_cast<int>(s.rfind('a'));
        int bIdx = (s.find('b') == std::string::npos) ? INT_MAX : static_cast<int>(s.find('b'));
        return aIdx < bIdx;
    }
};
*/

/*
class Solution {
class Solution {
public:
    bool checkString(string s) {
        bool b_found = false;
        
        for (char c : s) {
            if (c == 'b') {
                b_found = true;
            } else if (c == 'a' && b_found) {
                // 如果已經找到過 'b'，後面卻又出現 'a'，則違規
                return false;
            }
        }
        
        return true;
    }
};
*/
