/**
 * 題目：2022. Convert 1D Array Into 2D Array (將一維陣列轉變為二維陣列)
 * 難度：簡單 (Easy)
 * 描述：給你一個下標從 0 開始的一維整數陣列 original，以及兩個整數 m 和 n。
 *      你需要使用 original 中所有的元素建立一個 m 行 n 列的二維陣列。
 *      若無法構成（元素總數不符），則回傳空的二維陣列。
 * 
 * 時間複雜度：O(m * n) - 需要遍歷 original 陣列中的所有元素一次。
 * 空間複雜度：O(1) - 除了存儲結果所需的空間外，沒有使用額外的輔助空間。
 * 
 * 解法思路：
 * 1. 首先判斷合法性：如果 m * n 不等於 original 的長度，說明無法填滿或元素過多，回傳 {}。
 * 2. 初始化一個 m 行 n 列的二維向量 res。
 * 3. 遍歷一維陣列 original，利用索引 i 計算其在二維陣列中的位置：
 *    - 列索引 (Row index) = i / n （目前是第幾個長度為 n 的區段）
 *    - 行索引 (Column index) = i % n （在該區段中的偏移量）
 * 4. 將數值填入對應位置後回傳結果。
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // 合法性檢查：元素總數必須完全等於 m * n
        if (m * n != original.size()) {
            return {};
        }

        // 初始化二維陣列：m 列，每列有 n 個元素
        vector<vector<int>> res(m, vector<int>(n));

        // 進行維度轉換映射
        for (int i = 0; i < original.size(); i++) {
            // i / n 決定第幾列，i % n 決定第幾行
            res[i / n][i % n] = original[i];
        }

        return res;
    }
};
