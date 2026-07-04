/**
 * 題目：784. Letter Case Permutation
 * 難度：中等 (Medium)
 * 描述：透過改變字母大小寫，找出所有可能的組合。
 * * 優化重點：
 * 1. 預分配空間：透過計算字母數量預先 reserve 結果容器，減少記憶體重分配。
 * 2. 減少函式呼叫：透過位元運算優化大小寫轉換 (僅限 ASCII 字母)。
 */

class Solution {
private:
    void backtrack(string& s, int index, vector<string>& res) {
        while (index < s.size() && isdigit(s[index])) {
            index++;
        }
        if(index == s.size()) {
            res.push_back(s);
            return;
        }
        s[index] = tolower(s[index]);
        backtrack(s, index + 1, res);
        s[index] = toupper(s[index]);
        backtrack(s, index + 1, res);
    } 
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        backtrack(s, 0, res);
        return res;
    }
};
