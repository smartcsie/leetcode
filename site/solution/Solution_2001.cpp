/**
 * 題目：2001. Number of Pairs of Interchangeable Rectangles (可互換矩形的對數)
 * 難度：中等 (Medium)
 * * 描述：
 * 給定一個二維整數陣列 rectangles，其中 rectangles[i] = [width_i, height_i]。
 * 若兩個矩形的寬高比相同（width1 / height1 == width2 / height2），則稱它們為可互換的。
 * 計算陣列中可互換矩形的對數。
 * * 設計思路：
 * 1. 為了判斷矩形是否可互換，我們計算每個矩形的寬高比 (width / height)。
 * 2. 使用雜湊表 (unordered_map) 記錄每個比例出現的次數。
 * 3. 遍歷過程中，若當前比例已出現過 k 次，則代表能與當前矩形組成 k 個新配對。
 * * 時間複雜度：O(N) - N 為矩形數量，遍歷一次矩陣。
 * 空間複雜度：O(N) - 最壞情況下每個矩形的比例都不同。
 */

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int> count;
        long long res = 0;
        for(const vector<int>& rectangle : rectangles) {
            double ratio = (double) rectangle[0] / rectangle[1];
            res += count[ratio];
            count[ratio]++;
        }
        return res;
    }
};
