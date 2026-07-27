/**
 * 題目：2001. Number of Pairs of Interchangeable Rectangles (可互換矩形的對數)
 * 難度：中等 (Medium)
 * 描述：找出寬高比相同的矩形對數量。
 * * 時間複雜度：O(N * log(min(w, h))) - log 部分來自 GCD 計算。
 * 空間複雜度：O(N) - 儲存每個比例的出現次數。
 * * 優化思路：
 * 將寬高比 (width/height) 透過 GCD 約分至最簡分數，避免浮點數運算帶來的誤差風險。
 */

// 自定義 Hash 函式，用於 unordered_map 儲存 pair<int, int>
struct pair_hash {
    inline size_t operator()(const pair<int, int> & v) const {
        return v.first * 31 + v.second;
    }
};

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        // 使用 pair<int, int> 儲存 {width/gcd, height/gcd}
        unordered_map<pair<int, int>, int, pair_hash> count;
        long long res = 0;
        
        for (const auto& r : rectangles) {
            int common = std::gcd(r[0], r[1]);
            pair<int, int> ratio = {r[0] / common, r[1] / common};
            
            // 累加當前比例已出現過的次數
            res += count[ratio];
            // 更新計數
            count[ratio]++;
        }
        
        return res;
    }
};
