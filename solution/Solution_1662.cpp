/**
 * 題目：1662. Check If Two String Arrays are Equivalent (檢查兩個字串陣列是否相等)
 * 難度：簡單 (Easy)
 * 描述：檢查兩個字串陣列連接後是否組成相同的字串。
 *
 * 時間複雜度：O(N+M)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 使用四個指標分別追蹤兩個陣列目前的「字串索引 (wordIdx)」與「字元索引 (charIdx)」。
 * 2. 同步遍歷兩個陣列，若在任意位置字元不匹配則回傳 false。
 * 3. 若某字串已遍歷完，則跳轉到下一個字串並將字元指標歸零。
 * 4. 最後檢查是否兩個陣列都同時到達結尾。
 */

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int w1 = 0, w2 = 0, c1 = 0 ,c2 = 0;
        while( w1 < word1.size() && w2 < word2.size() ) {
            if(word1[w1][c1] != word2[w2][c2]) return false;
            c1++;
            if(c1 == word1[w1].size()) { 
                w1++; 
                c1 = 0;
            }
            c2++;
            if(c2 == word2[w2].size()) { 
                w2++; 
                c2 = 0;
            }
        }
        return w1 == word1.size() && w2 == word2.size();
    }
};
