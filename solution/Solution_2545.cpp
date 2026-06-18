/**
 * 題目：2545. Sort the Students by Their Kth Score (依照第 K 個分數排序學生)
 * 難度：中等 (Medium)
 * 描述：根據每個學生在第 k 個考試的分數，對所有學生進行從高到低的排序。
 * * 時間複雜度：O(M * N log N)，M 為行數，N 為欄數。
 * 空間複雜度：O(1) - 原地排序。
 * * 優化思路：
 * 1. 簡化比較邏輯：直接比較 v1[k] 與 v2[k]，不需要額外的判斷式。
 * 2. 移除冗餘判斷：題目未要求在分數相同時處理次要排序，移除 v1 < v2 可提升效能。
 */

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>>& sortTheStudents(std::vector<std::vector<int>>& score, int k) {
        // 使用 lambda 表達式直接對 score 進行降序排序
        std::sort(score.begin(), score.end(), [&](const std::vector<int>& v1, const std::vector<int>& v2) {
            return v1[k] > v2[k];
        });
        
        return score;
    }
};
