/**
 * 題目：1897. Redistribute Characters to Make All Strings Equal
 * 難度：簡單 (Easy)
 * 描述：判斷是否能透過重分配字元，讓所有單字變得一模一樣。
 *
 * 時間複雜度：O(N*M)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 統計所有字元出現的總次數。
 * 2. 如果要讓 n 個單字變得完全一樣，每個字元總出現次數必須是 n 的倍數。
 * 3. 若有任何字元的總次數無法被 n 整除，則無法均分，回傳 false。
 */

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        array<uint16_t, 26> counts{};
        int n = words.size();
        for(const string& word : words) {
            for(const char& c : word) counts[c - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(counts[i] == 0) continue;
            if((counts[i] % n) != 0) return false;;
        }
        return true;
    }
};