/**
 * 題目：2553. Separate the Digits in an Array (分割陣列中的數字)
 * 難度：簡單 (Easy)
 * 描述：將陣列中的每個整數拆分成獨立的數位，並維持原始順序放入新陣列。
 * 
 * 優化方向：
 * 為了避免使用 stack 這種較重的資料結構，可以先將位數存入臨時 vector，
 * 再將其反轉，或者直接由高位向低位提取。
 */

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for (int num : nums) {
            string s = to_string(num); // 轉為字串處理最為直觀
            for (char c : s) {
                res.push_back(c - '0');
            }
        }
        return res;
    }
};
