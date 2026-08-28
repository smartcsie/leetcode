/**
 * 題目：179. Largest Number (最大數)
 * 難度：中等 (Medium)
 * 描述：給定一組整數，重新排列它們組成最大的整數。
 *
 * 時間複雜度：O(NlogN*K)
 * 空間複雜度：O(N*K)
 *
 * 解法思路：
 * 1. 先將所有整數轉換為字串，避免在排序過程中反覆呼叫 to_string。
 * 2. 使用自訂比較規則：比較 (a + b) 與 (b + a) 的字典序大小。
 * 3. 處理特殊邊界：若排序後第一個字串為 "0"，代表陣列中最大值為 0，直接回傳 "0"。
 */

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans;
        int n = nums.size();
        vector<string> str_nums(n);
        for(int i =0; i < n; i++) {
            str_nums[i] = to_string(nums[i]);
        }
        sort(str_nums.begin(), str_nums.end(), [](const string& s1, const string& s2) {
            return s1 + s2 > s2 + s1;
        });
        if(str_nums[0] == "0") return "0";
        for(const string& s : str_nums) ans += s;
        return ans;
    }
};
