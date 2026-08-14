/**
 * 題目：1935. Maximum Number of Words You Can Type
 * 難度：待補充
 * 描述：計算在給定壞掉鍵盤的情況下，有多少個完整的單字可以被完全輸入。
 *
 * 時間複雜度：O(N*M) - 對每個單字檢查是否含有壞掉的字母。
 * 空間複雜度：O(1) - 僅使用常數空間。
 *
 * 解法思路：
 * 1. 使用 istringstream 將 text 切分成多個單字。
 * 2. 針對每個單字進行檢查，若單字中包含任何一個 brokenLetters，則該單字無法輸入。
 * 3. 統計未被標記為「損壞」的單字數量。
 */

class Solution {
public:
    int canBeTypedWords(std::string text, std::string brokenLetters) {
        int mask = 0;
        for(const char& c : brokenLetters) mask |= 1 << (c - 'a');
        istringstream iss(text);
        string word;
        int n = 0;
        int count = 0;
        while(iss >> word) {
            int submask = 0;
            for(const char& c : word) submask |= 1 << (c - 'a');
            if(mask & submask) count++;
            n++;
        }
        return n - count;
    }
};
