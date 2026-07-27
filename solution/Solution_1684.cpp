/**
 * 題目：1684. Count the Number of Consistent Strings (統計一致字串的數目)
 * 難度：簡單 (Easy)
 * 描述：若字串中的所有字元都在 allowed 字串中，則為一致字串。
 * * 時間複雜度：O(N * M) - N 為單字總數，M 為單字平均長度。
 * 空間複雜度：O(1) - 使用固定大小的整數作為狀態儲存。
 * * 優化思路：
 * 利用 26-bit 的整數作為遮罩 (Mask)，將 allowed 字串的資訊映射到位元上，
 * 使檢查字元是否存在變成單純的位元 AND 運算。
 */

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask = 0;
        for(char c : allowed) {
            mask |=  1 << (c - 'a');
        }
        int res = words.size();
        for(const string& word : words) {
            for(char c : word) {
                if(!(mask & 1 << (c - 'a'))) {
                    res--;
                    break;
                }
            }
        }
        return res;
    }
};
