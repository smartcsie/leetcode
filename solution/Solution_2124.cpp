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
        return s.find("ba") == string::npos;
    }
};
