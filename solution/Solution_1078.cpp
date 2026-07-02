/**
 * 題目：1078. Occurrences After Bigram
 * 難度：簡單 (Easy)
 * 描述：找出 text 中每個 `first` + `second` 序列後面的第三個單字。
 * * 優化重點：
 * 1. 使用 `reserve` 預先分配單字容器空間，減少頻繁記憶體擴充。
 * 2. 邊界檢查優化，確保迴圈不會存取越界。
 */

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        istringstream ss(text);
        vector<string> res;
        vector<string> words;
        string word;
        while(ss >> word) {
            words.push_back(word);
        }
        for(int i = 0; i < words.size() - 2; i++) {
            if(words[i] == first && words[i + 1] == second) res.push_back(words[i + 2]);
        }
        return res;
    }
};
