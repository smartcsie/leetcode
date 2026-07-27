/**
 * 題目：1980. Find Unique Binary String (找出不同的二進位字串)
 * 難度：中等 (Medium)
 * 描述：在給定的 N 個長度為 N 的二進位字串陣列中，找出一個不在其中的二進位字串。
 * * 時間複雜度：O(N^2) - 遍歷 N 個字串，每個字串長度 N。
 * 空間複雜度：O(N) - 儲存結果字串。
 * * 優化思路：
 * 康托爾對角線證明 (Cantor's Diagonal Argument)：
 * 若我們構造一個字串 `res`，使得 `res[i]` 永遠與 `nums[i][i]` 相反，
 * 那麼 `res` 一定不會與任何 `nums[i]` 相等。
 */

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res = "";
        for(int i = 0; i < nums.size(); i++) {
            res += (nums[i][i] == '0') ? "1" : "0";
        }
        return res;
    }
};
