/**
 * 題目：1291. Sequential Digits
 * 難度：中等 (Medium)
 * 描述：找出所有範圍 [low, high] 內的「順序數字」。
 * * 優化重點：
 * 1. 窮舉法：所有可能的順序數字總共不超過 40 個，窮舉最快。
 * 2. 字串截取：利用 "123456789" 作為模板進行截取。
 */

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> res;
        for(int len = 2; len <= 9; len++) {
            for(int i= 0; i <= 9 -len; i++) {
                int x = stoi(s.substr(i, len));
                if(x >= low && x <= high) res.push_back(x);
            }
        }
        ranges::sort(res);
        return res;
    }
};
