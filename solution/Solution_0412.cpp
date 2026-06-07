/**
 * 題目：412. Fizz Buzz
 * 難度：簡單 (Easy)
 * 描述：根據數字輸出 "Fizz", "Buzz", "FizzBuzz" 或數字本身。
 * * 時間複雜度：O(N) - 遍歷 1 到 n。
 * 空間複雜度：O(1) - 輸出空間不計入輔助空間。
 * * 優化思路：
 * 利用字串拼接 (String Concatenation) 的技巧，避免巢狀或冗長的 if-else 判斷。
 * 只要能被 3 整除就加上 "Fizz"，被 5 整除就加上 "Buzz"，
 * 若拼接後的字串為空，則放入數字本身。
 */

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        res.reserve(n); // 預留空間，避免 vector 動態擴容開銷

        for (int i = 1; i <= n; i++) {
            string temp = "";
            
            // 邏輯模組化，方便未來新增規則
            if (i % 3 == 0) temp += "Fizz";
            if (i % 5 == 0) temp += "Buzz";
            
            if (temp.empty()) {
                res.push_back(to_string(i));
            } else {
                res.push_back(temp);
            }
        }
        return res;
    }
};
