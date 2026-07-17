/**
 * 題目：942. DI String Match
 * 描述：給定一個長度為 N 的字串 s，由 'I' (增加) 與 'D' (減少) 組成，
 *       輸出一個排列，滿足當 s[i] == 'I' 時 p[i] < p[i+1]，s[i] == 'D' 時 p[i] > p[i+1]。
 * 
 * 解法思路：
 * 1. 為了滿足增減規則，我們使用兩個指標：`i` (目前最小值) 與 `d` (目前最大值)。
 * 2. 遍歷字串 s：
 *    - 若遇到 'I'，表示後面必須比現在大，因此放入目前的最小值 `i++`。
 *    - 若遇到 'D'，表示後面必須比現在小，因此放入目前的最大值 `d--`。
 * 3. 迴圈結束後，最後剩下的一個數 (i == d) 放入陣列尾端即可。
 */

class Solution {
public:
    std::vector<int> diStringMatch(std::string s) {
        std::vector<int> ans;
        int i = 0;              // 指向目前範圍的最小值
        int d = s.length();      // 指向目前範圍的最大值
        
        for (const char c : s) {
            if (c == 'I') {
                ans.push_back(i++);
            } else {
                ans.push_back(d--);
            }
        }
        
        // 最後一個數字放入陣列
        ans.push_back(i); 
        
        return ans;
    }
};
