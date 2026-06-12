/**
 * 題目：3769. Sort Integers by Binary Reflection
 * 難度：中等 (Medium)
 * 描述：根據整數的二進位反轉值進行排序，若反轉值相同，則按原數值大小排序。
 * * 時間複雜度：O(N log N) - 排序操作為主導因素。
 * 空間複雜度：O(N) - 額外儲存反射對結構。
 * * 優化思路：
 * 1. 預分配 (Reserve)：使用 `reserve` 避免 `push_back` 時的記憶體重新配置。
 * 2. 結構簡化：直接利用 `std::pair` 的字典序特性，減少自定義比較函數的複雜度。
 */

class Solution {
private: 
    // 將整數進行位元反轉 (Binary Reflection)
    int getReflection(int n) {
        int reflect = 0;
        while (n > 0) {
            reflect = (reflect << 1) | (n & 1);
            n >>= 1;
        }
        return reflect;
    }

public:
    vector<int> sortByReflection(vector<int>& nums) {
        int n = nums.size();
        // 預分配空間，避免動態擴容開銷
        vector<pair<int, int>> pairs;
        pairs.reserve(n);

        // 計算反射值並存入配對
        for (const int& num : nums) {
            pairs.push_back({getReflection(num), num});
        }

        // 利用 pair 預設排序規則：先比第一個元素(反射值)，再比第二個元素(原值)
        sort(pairs.begin(), pairs.end());

        // 提取排序後的結果
        vector<int> res;
        res.reserve(n);
        for (const auto& element : pairs) {
            res.push_back(element.second);
        }
        
        return res;
    }
};
