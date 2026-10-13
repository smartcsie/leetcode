/**
 * 題目：942. DI String Match
 * 難度：中等 (Medium)
 * 描述：給定一個長度為 N 的字串 s，由 'I' (增加) 與 'D' (減少) 組成，
 * 輸出一個排列，滿足當 s[i] == 'I' 時 p[i] < p[i+1]，s[i] == 'D' 時 p[i] > p[i+1]。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 1. 為了滿足增減規則，我們使用兩個指標：`i` (目前最小值) 與 `d` (目前最大值)。
 * 2. 遍歷字串 s：
 * - 若遇到 'I'，表示後面必須比現在大，因此放入目前的最小值 `i++`。
 * - 若遇到 'D'，表示後面必須比現在小，因此放入目前的最大值 `d--`。
 * 3. 迴圈結束後，最後剩下的一個數 (i == d) 放入陣列尾端即可。
 */

class Solution {
public:
    std::vector<int> diStringMatch(std::string s) {
        int n = s.size() + 1;
        int left = 0, right = n - 1;
        vector<int> ans(n);
        for(int i = 0 ; i < n; i++) {
            ans[i] = (s[i] == 'I') ? left++ : right--;
        }
        return ans;
    }
};
