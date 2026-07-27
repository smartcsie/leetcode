/**
 * 題目：2553. Separate the Digits in an Array (分割陣列中的數字)
 * 難度：簡單 (Easy)
 * 描述：將陣列中的每個整數拆分成獨立的數位，並維持原始順序放入新陣列。
 * 優化方向：
 * 為了避免使用 stack 這種較重的資料結構，可以先將位數存入臨時 vector，
 * 再將其反轉，或者直接由高位向低位提取。
 *
 * 時間複雜度：O(N * log(max_val)) - 對每個數字做 digit decomposition 後加入結果。
 * 空間複雜度：O(N * log(max_val)) - 結果陣列大小為各數字位數總和。
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
