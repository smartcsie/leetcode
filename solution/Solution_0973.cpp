/**
 * 題目：973. K Closest Points to Origin (最接近原點的 K 個點)
 * 難度：中等 (Medium)
 * 描述：在平面上給定一組座標點，回傳距離原點最近的 K 個點。
 * * 時間複雜度：O(N) - nth_element 平均線性時間。
 * 空間複雜度：O(1) - 原地修改陣列（不算回傳結果空間）。
 * * 優化思路：
 * 1. 原地計算距離並 push_back 到點陣列末端，避免額外記憶體配置。
 * 2. 使用 nth_element 在 O(N) 時間內完成分區。
 * 3. pop_back 移除計算值，還原點的座標資訊。
 */

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // 原地計算平方距離 (x^2 + y^2)，不需開根號以維持精度與效率
        for (auto& point : points) {
            point.push_back(point[0] * point[0] + point[1] * point[1]);
        }
        
        // 使用 nth_element 定位前 k 個最近的點
        auto target = points.begin() + k;
        nth_element(points.begin(), target, points.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[2] < b[2]; // 比較第三欄的距離值
        });
        
        // 整理結果：移除距離欄位並填入結果集
        vector<vector<int>> res;
        res.reserve(k);
        for (int i = 0; i < k; ++i) {
            points[i].pop_back(); // 還原為 [x, y]
            res.push_back(move(points[i])); // 使用 move 避免不必要的拷貝
        }
        
        return res;
    }
};
