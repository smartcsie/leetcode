/**
 * 題目：1805. Number of Different Integers in a String
 * 難度：簡單 (Easy)
 * 描述：計算字串中不同的數字整數個數（前導零視為相同）。
 * * 時間複雜度：O(N) - N 為字串長度，需遍歷字串並進行處理。
 * 空間複雜度：O(N) - 使用 Hash Set 儲存處理後的唯一數字字串。
 * * 解法思路：
 * 1. 將所有字母替換為空格，使數字被空格自然分隔。
 * 2. 使用 stringstream 讀取每個數字片段。
 * 3. 處理前導零：使用 `find_first_not_of('0')` 找到第一個非零位，並截取子字串；若全是 '0'，則視為 "0"。
 * 4. 將處理後的字串加入 `unordered_set` 以自動去重。
 */

class Solution {
public:
    int numDifferentIntegers(string word) {
        for(char& c : word) {
            if(isalpha(c)) c = ' ';
        }
        istringstream ss(word);
        string strNum;
        unordered_set<string> uniqueNums;
        while(ss >> strNum) {
            size_t first_not_zero = strNum.find_first_not_of('0');
            if (first_not_zero == std::string::npos) {
                uniqueNums.insert("0");
            } else {
                uniqueNums.insert(strNum.substr(first_not_zero));
            }
        }
        return uniqueNums.size();
    }
};
