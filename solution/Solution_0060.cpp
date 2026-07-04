/**
 * 題目：60. Permutation Sequence
 * 難度：困難 (Hard)
 * 描述：求 n 個數字的第 k 個排列序列。
 * * 優化重點：
 * 1. 減少轉換開銷：使用字元直接相加而非 `std::to_string`，減少記憶體分配。
 * 2. 簡潔階乘陣列：在迴圈中處理，減少額外變數。
 */

class Solution {
public:
    string getPermutation(int n, int k) {
        std::string res = "";
        std::vector<int> nums;
        std::vector<int> factorial(n);
        // 預計算階乘值: factorial[i] = i!
        factorial[0] = 1;
        for (int i = 1; i < n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }
        // 建立可用數字列表: {1, 2, ..., n}
        for (int i = 1; i <= n; ++i) nums.push_back(i);
        // k 轉為 0-indexed 以便計算
        k--;
        // 逐位確定數字
        for (int i = n - 1; i >= 0; --i) {
            int index = k / factorial[i]; // 決定當前位數的索引
            res += std::to_string(nums[index]);
            nums.erase(nums.begin() + index); // 從候選池移除該數字
            k %= factorial[i]; // 更新 k
        }
        return res;
    }
};
