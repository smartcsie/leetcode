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
        int ans = 0;
        for(int cIdx = 0; cIdx < strs[0].size(); cIdx++) {
            for(int sIdx = 1; sIdx < strs.size(); sIdx++) {
                if(strs[sIdx - 1][cIdx] > strs[sIdx][cIdx]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};