/**
 * 題目：2553. Separate the Digits in an Array (分割陣列中的數字)
 * 難度：簡單 (Easy)
 * 描述：將陣列中的每個整數拆分成獨立的數位，並維持原始順序放入新陣列。
 * 優化方向：
 * 為了避免使用 stack 這種較重的資料結構，可以先將位數存入臨時 vector，
 * 再將其反轉，或者直接由高位向低位提取。
 *
 * 時間複雜度：O(N*log(max_VAL)) - 對每個數字做 digit decomposition 後加入結果。
 * 空間複雜度：O(N*log(max_VAL)) - 結果陣列大小為各數字位數總和。
 */

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i = nums.size() - 1; i >= 0; i--) {
            int temp = nums[i];
            while(temp > 0) {
                ans.push_back(temp % 10);
                temp /= 10;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
