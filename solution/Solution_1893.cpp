/**
 * 題目：1893. Check if All the Integers in a Range Are Covered
 * 描述：給你一個二維整數陣列 ranges 和兩個整數 left 和 right。
 *       如果 ranges 中的每個區間共同覆蓋了範圍 [left, right] 中的所有整數，
 *       則返回 true，否則返回 false。
 * 
 * 解法思路：
 * 1. 觀察到題目的數值範圍非常小（根據 LeetCode 測資，座標通常在 1 到 50 之間）。
 * 2. 宣告一個大小為 51 的 `std::bitset<51>` 來代表數字 0 到 50 是否被覆蓋。
 * 3. 走訪 ranges 中的每一個區間 [start, end]，使用內建的迴圈將對應的 bit 位置設為 1（bits.set(i)）。
 * 4. 檢查目標區間 [left, right]，若其中有任何一個整數的 bit 檢查為 0（即未被覆蓋），直接返回 false。
 * 5. 若檢查完畢皆為 1，則返回 true。
 */

class Solution {
public:
    bool isCovered(std::vector<std::vector<int>>& ranges, int left, int right) {
        // 宣告一個 51 個 bit 的 bitset (對應 0~50 的數值範圍)
        std::bitset<51> bits;
        
        // 1. 將所有 ranges 涵蓋的數值在 bitset 中標記為 1
        for (const std::vector<int>& range : ranges) {
            for (int i = range[0]; i <= range[1]; i++) {
                bits.set(i);
            }
        }
        
        // 2. 檢查目標區間 [left, right] 是否每一個 bit 都被設為 1
        for (int i = left; i <= right; i++) {
            if (!bits.test(i)) {
                return false;
            }
        }
        
        return true;
    }
};
