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
        vector<int> idx1(2, 0), idx2(2, 0);
        int size1 = 0, size2 = 0;
        for(const string& s : word1) size1 += s.size();
        for(const string& s : word2) size2 += s.size();
        if(size1 != size2) return false;
        int count = 0;
        while(count++ < size1) {
            if(word1[idx1[0]][idx1[1]] != word2[idx2[0]][idx2[1]]) return false;
            idx1[1]++;
            if(idx1[1] == word1[idx1[0]].size()) {
                idx1[0]++;
                idx1[1] = 0;
            }
            idx2[1]++;
            if(idx2[1] == word2[idx2[0]].size()) {
                idx2[0]++;
                idx2[1] = 0;
            }
               
        }
        return true;
    }
};
