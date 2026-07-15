/**
 * 題目：832. Flipping an Image
 * 難度：簡單 (Easy)
 * 描述：對二維二進位矩陣進行水平翻轉後，再將所有元素取反 (0變1, 1變0)。
 * 
 * 解法思路：
 * 1. 對矩陣中的每一行執行 `std::reverse` 進行水平翻轉。
 * 2. 遍歷每一行的元素，使用 `!` (邏輯非) 運算子進行取反。
 */

class Solution {
public:
    std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& image) {
        for (auto& row : image) {
            // 1. 水平翻轉
            std::reverse(row.begin(), row.end());
            // 2. 取反 (XOR 1 也可以達成取反效果: val ^= 1)
            for (int& val : row) {
                val ^= 1; 
            }
        }
        return image;
    }
};
