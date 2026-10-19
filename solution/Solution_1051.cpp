/**
 * 題目：1051. Height Checker (高度檢查器)
 * 難度：簡單 (Easy)
 * 描述：統計與非遞減排序後陣列不相符的索引數量。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(K)
 *
 * 解法思路：
 * (Counting Sort)：
 * 由於身高範圍有限 (1-100)，我們不需進行 O(N log N) 的排序。
 * 建立一個頻率陣列紀錄每個高度出現次數，再依序比對即可。
 */

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        array<int, 101> counts = {};
        for(const int& x : heights) counts[x]++;
        int mismatchCount = 0;
        int expectedHeight = 0;
        for (const int& actualHeight : heights) {
            // 尋找下一個非零的排序高度
            while (expectedHeight < 101 && counts[expectedHeight] == 0) {
                expectedHeight++;
            }
            // 如果實際高度與預期排序高度不同，計數加一
            if (actualHeight != expectedHeight) {
                mismatchCount++;
            }
            // 用掉一個該高度的額度
            counts[expectedHeight]--;
        }
        return mismatchCount;
    }
};
