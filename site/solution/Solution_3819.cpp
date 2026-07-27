/**
 * 題目：3819. Rotate Non Negative Elements
 * 難度：簡單 (Easy)
 * 描述：將陣列中所有非負數向左旋轉 k 位，負數保持原位。
 * * 時間複雜度：O(N)，其中 N 為陣列長度。
 * 空間複雜度：O(N)，用於儲存非負數的臨時容器。
 * * 優化思路：
 * 1. 使用 reserve() 減少動態記憶體分配次數。
 * 2. 透過 range-based for loop 與 reference 寫回原陣列，提升可讀性。
 */

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> rotateElements(std::vector<int>& nums, int k) {
        // 1. 預先收集非負數，並使用 reserve 減少開銷
        std::vector<int> nonNegs;
        nonNegs.reserve(nums.size()); 
        for(const int num : nums) {
            if(num >= 0) nonNegs.push_back(num);
        }
        
        // 若無非負數或無需旋轉，直接返回
        if (nonNegs.empty()) return nums;
        
        // 2. 規範化 k 的值，確保 rotate 不會越界
        int n = static_cast<int>(nonNegs.size());
        k %= n;
        
        // 3. 使用標準庫原地旋轉，效率極高 (三段翻轉法)
        std::rotate(nonNegs.begin(), nonNegs.begin() + k, nonNegs.end());
        
        // 4. 將旋轉後的結果放回原陣列
        int j = 0;
        for(int& num : nums) {
            if(num >= 0) {
                num = nonNegs[j++];
            }
        }
        
        return nums;
    }
};
