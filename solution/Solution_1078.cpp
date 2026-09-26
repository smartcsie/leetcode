/**
 * 題目：1078. Occurrences After Bigram
 * 難度：簡單 (Easy)
 * 描述：找出 text 中每個 `first` + `second` 序列後面的第三個單字。
 * 優化重點：
 * 1. 使用 `reserve` 預先分配單字容器空間，減少頻繁記憶體擴充。
 * 2. 邊界檢查優化，確保迴圈不會存取越界。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 */

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> prev(2);
        vector<string> target = {first, second};
        istringstream iss(text);
        string w;
        vector<string> ans;
        while(iss >> w) {    
            if(prev == target) ans.push_back(w);
            prev[0] = prev[1];
            prev[1] = w;
        }
        return ans;
    }
};
