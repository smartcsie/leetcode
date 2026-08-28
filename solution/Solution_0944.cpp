/**
 * 題目：944. Delete Columns to Make Sorted (刪除行以使其排序)
 * 難度：簡單 (Easy)
 * 描述：檢查矩陣的每一行，統計有多少行不符合非遞減順序。
 *
 * 時間複雜度：O(N*M)
 * 空間複雜度：O(M)
 *
 * 解法思路：
 * 1. 快速標記：使用 bitset 追蹤不合規的列，避免重複檢查或多餘統計。
 * 2. 提前中斷：若一列已確定不合法，後續行無需再比較該列。
 */

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();
        int ans = 0;
        for(int j = 0; j < n; j++) {
            bool sorted = true;
            for(int i = 0; i < m - 1; i++) {
                if(strs[i][j] > strs[i + 1][j]) {
                    sorted = false;
                    break;
                }
            }
            if(!sorted)ans++; 
        }
        return ans;
    }
};
