/**
 * 題目：944. Delete Columns to Make Sorted (刪除行以使其排序)
 * 難度：簡單 (Easy)
 * 描述：檢查矩陣的每一行，統計有多少行不符合非遞減順序。
 * * 時間複雜度：O(N * M) - N 為字串個數，M 為字串長度。
 * 空間複雜度：O(M) - bitset 大小取決於字串長度 M。
 * * 優化思路：
 * 1. 快速標記：使用 bitset 追蹤不合規的列，避免重複檢查或多餘統計。
 * 2. 提前中斷：若一列已確定不合法，後續行無需再比較該列。
 */

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        if(strs.empty()) return 0;
        int rowSize = strs.size();
        int colSize = strs[0].size();
        bitset<1001> unsorted;
        for(int j = 0; j < colSize; j++) {
            for(int i = 1; i < rowSize; i++) {
                if(strs[i][j] < strs[i - 1][j]) {
                    unsorted.set(j);
                    break;
                } 
            }
        }
        return static_cast<int>(unsorted.count());
    }
};
