/**
 * 題目：179. Largest Number (最大數)
 * 難度：中等 (Medium)
 * 描述：給定一組整數，重新排列它們組成最大的整數。
 * * 時間複雜度：O(NlogN * k)，其中 N 是陣列長度，k 是數字轉換為字串的平均長度。
 * 空間複雜度：O(N * k) - 用於儲存字串陣列。
 * * 優化思路：
 * 1. 先將所有整數轉換為字串，避免在排序過程中反覆呼叫 to_string。
 * 2. 使用自訂比較規則：比較 (a + b) 與 (b + a) 的字典序大小。
 * 3. 處理特殊邊界：若排序後第一個字串為 "0"，代表陣列中最大值為 0，直接回傳 "0"。
 */

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str_nums;
        str_nums.reserve(nums.size());
        
        // 預先轉換為字串，提升排序效能
        for (int num : nums) {
            str_nums.push_back(to_string(num));
        }
        
        // 自訂排序規則
        sort(str_nums.begin(), str_nums.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        
        // 如果最大的數是 "0"，則結果必為 "0" (例如 [0, 0] -> "0")
        if (str_nums[0] == "0") return "0";
        
        string res;
        for (const string& s : str_nums) {
            res += s;
        }
        
        return res;
    }
};
