/**
 * 題目：771. Jewels and Stones (寶石與石頭)
 * 難度：簡單 (Easy)
 * 描述：計算石頭中有多少顆是寶石。寶石種類由字串 jewels 定義。
 *
 * 時間複雜度：O(J+S)
 * 空間複雜度：O(J)
 *
 * 解法思路：
 * 1. 雜湊集合：將 jewels 放入 unordered_set，實現 O(1) 的查找速度。
 */

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        bitset<128> bits;
        for(const char& c : jewels) bits.set(c);
        int ans = 0;
        for(const char& c : stones) if(bits.test(c)) ans++;
        return ans;
    }
};
