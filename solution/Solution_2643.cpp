/**
 * 題目：2643. Row With Maximum Ones
 * 難度：簡單 (Easy)
 * 描述：找出二維陣列中包含最多 1 的那一行，回傳其索引與 1 的數量。
 * * 優化重點：
 * 1. 線性掃描：避免了排序所需的高昂開銷 O(M log M)。
 * 2. 空間優化：移除輔助陣列，直接比較更新極值，空間複雜度降至 O(1)。
 */

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int max_ones = -1;
        int max_index = -1;
        for(int i = 0; i < mat.size(); i++) {
            int ones = accumulate(mat[i].begin(), mat[i].end(), 0);
            if(ones > max_ones) {
                max_ones = ones;
                max_index = i;
            }
        }
        return {max_index, max_ones};
    }
};
