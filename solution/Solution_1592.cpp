/**
 * 題目：1592. Rearrange Spaces Between Words
 * 難度：簡單 (Easy)
 * 描述：重新排列字串中的空格，使得單字間的空格數相等，多餘的空格全部移至字串末尾。
 * 
 * 解法思路：
 * 1. 統計總空格數 (`spaces`)。
 * 2. 使用 `istringstream` 分割出所有單字並儲存至 `words` 容器。
 * 3. 處理兩種邊界情況：
 *    - 若只有一個單字 (`n == 1`)：直接將所有空格補在單字後面。
 *    - 若有多個單字 (`n > 1`)：
 *      - 單字間空格數 = `spaces / (n - 1)`
 *      - 字串末尾空格數 = `spaces % (n - 1)`
 */

class Solution {
public:
    string reorderSpaces(string text) {
        int spaces = 0;
        for(const char& c : text) {
            if(c == ' ') spaces ++;
        }
        if(spaces == 0) return text;
        istringstream ss(text);
        string word;
        vector<string> words;
        while(ss >> word) {
            words.push_back(word);
        }
        string ans;
        int n = words.size();
        for(int i = 0; i < n; i++) {
            ans.append(words[i]);
            if(i != (n - 1)) {
                ans.append(string(spaces/(n - 1), ' '));
            } else if(n > 1){
                ans.append(string(spaces % (n - 1), ' '));
            } else if(n == 1){
                ans.append(string(spaces , ' '));
            }
        }
        return ans;
    }
};
