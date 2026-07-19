/**
 * 題目：1897. Redistribute Characters to Make All Strings Equal
 * 描述：判斷是否能透過重分配字元，讓所有單字變得一模一樣。
 * 
 * 解法思路：
 * 1. 統計所有字元出現的總次數。
 * 2. 如果要讓 n 個單字變得完全一樣，每個字元總出現次數必須是 n 的倍數。
 * 3. 若有任何字元的總次數無法被 n 整除，則無法均分，回傳 false。
 */

class Solution {
public:
    bool makeEqual(std::vector<std::string>& words) {
        std::vector<int> counts(26, 0);
        int n = words.size();
        // 1. 計算所有單字中每個字元的總出現頻率
        for (const std::string& word : words) {
            for (const char& c : word) {
                counts[c - 'a']++;
            }
        }
        // 2. 檢查總頻率是否皆能被 n 整除
        for (int count : counts) {
            if (count % n != 0) {
                return false;
            }
        }
        return true;
    }
};
