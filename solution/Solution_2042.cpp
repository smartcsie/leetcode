/**
 * 題目：2042. Check if Numbers Are Ascending in a Sentence (檢查句子中的數字是否遞增)
 * 難度：簡單 (Easy)
 * 描述：檢查句子中的數字是否嚴格遞增（不包含空格）。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 使用 `stringstream` 或直接遍歷字串來解析數字。
 * 2. 維護一個 `prev` 變數記錄前一個遇到的數字，初始設為 -1。
 * 3. 每次解析到新數字時，判斷是否大於 `prev`。
 */

class Solution {
public:
    bool areNumbersAscending(string s) {
        istringstream iss(s);
        string w;
        int pre = -1;
        int cur = -1;
        while(iss >> w) {
            if(isdigit(w[0])) {
                cur = stoi(w);
                if(pre != -1 && cur <= pre) return false;
                pre = cur;
            }
        }
        return true;
    }
};
