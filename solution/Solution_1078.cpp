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
        string pre1, pre2;
        vector<string> ans;
        int n = text.size();
        for(int i = 0, start = 0; i <= n; i++) {
            if(i == n || text[i] == ' ') {
                string str = text.substr(start, i - start);
                if(pre1 == first && pre2 == second) {
                    ans.push_back(str);
                }
                pre1 = pre2;
                pre2 = str;
                start = i + 1;
            }
        }
        return ans;
    }
};