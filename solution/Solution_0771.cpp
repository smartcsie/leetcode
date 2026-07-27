/**
 * 題目：771. Jewels and Stones (寶石與石頭)
 * 難度：簡單 (Easy)
 * 描述：計算石頭中有多少顆是寶石。寶石種類由字串 jewels 定義。
 * * 時間複雜度：O(J + S) - J 為寶石種類數，S 為石頭總數。
 * 空間複雜度：O(J) - 用於儲存寶石集合。
 * * 優化思路：
 * 1. 雜湊集合：將 jewels 放入 unordered_set，實現 O(1) 的查找速度。
 */

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelSet(jewels.begin(), jewels.end());
        int count = 0;
        for(const char& stone : stones) {
            if(jewelSet.contains(stone)) count++;
        }
        return count;
    }
};
