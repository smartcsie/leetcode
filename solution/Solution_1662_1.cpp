/**
 * 題目：1662. Check If Two String Arrays are Equivalent
 * 難度：簡單 (Easy)
 * 描述：給定兩個字串陣列 word1 和 word2，判斷兩個陣列拼接後的字串是否相等。
 *
 * 時間複雜度：O(N*L)
 * 空間複雜度：O(N*L)
 *
 * 解法思路：
 * （accumulate 拼接後比較）：
 * 用 accumulate 把各自陣列的所有字串依序拼接成一個完整字串，
 * 再直接比較兩個結果是否相等。
 */
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        return accumulate(word1.begin(), word1.end(), string(""))
            == accumulate(word2.begin(), word2.end(), string(""));
    }
};