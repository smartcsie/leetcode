/**
 * 題目：412. Fizz Buzz
 * 難度：簡單 (Easy)
 * 描述：根據數字輸出 "Fizz", "Buzz", "FizzBuzz" 或數字本身。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 利用字串拼接 (String Concatenation) 的技巧，避免巢狀或冗長的 if-else 判斷。
 * 只要能被 3 整除就加上 "Fizz"，被 5 整除就加上 "Buzz"，
 * 若拼接後的字串為空，則放入數字本身。
 */

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        for(int i = 0; i < n; i++) {
            if((i + 1) % 3 == 0 && (i + 1) % 5 == 0) {
                ans[i] = "FizzBuzz";
            } else if((i + 1) % 3 == 0) {
                ans[i] = "Fizz";
            } else if((i + 1) % 5 == 0) {
                ans[i] = "Buzz";
            } else {
                ans[i] = to_string(i + 1);
            }
        }
        return ans;
    }
};
