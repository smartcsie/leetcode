/**
 * 題目：1344. Angle Between Hands of a Clock
 * 難度：中等 (Medium)
 * 描述：計算時鐘上時針與分針之間較小的夾角。
 * * 優化重點：
 * 1. 角度轉換：時針每小時轉 30 度，每分鐘轉 0.5 度；分針每分鐘轉 6 度。
 * 2. 邊界處理：確保時針角度在 360 度範圍內 (處理 12 點情況)。
 * 3. 夾角計算：取兩者差值的絕對值，並確保夾角為較小的那個 (min(angle, 360 - angle))。
 */

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<char, pair<int, int>> direction = { {'N', {0, 1}}, {'S', {0, -1}}, {'E', {1, 0}},  {'W', {-1, 0}} };
        pair<int, int> cur = {0, 0};
        set<pair<int, int>> visited;
        visited.insert(cur);
        for(char c : path) {
            cur.first += direction[c].first;
            cur.second += direction[c].second;
            if(visited.contains(cur)) return true;
            visited.insert(cur);
        }
        return false;
    }
};
