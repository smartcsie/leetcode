/**
 * 題目：1029. Two City Scheduling
 * 難度：中等 (Medium)
 * 描述：給定 2n 個人要分配去 A、B 兩個城市面試，costs[i] = [costA,
 * costB] 是第 i 個人分別去兩個城市的花費，要求恰好一半人去 A、一半
 * 人去 B，求最小總花費。
 *
 * 時間複雜度：O(N log N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （Sorting + Greedy Decision，這題是這個技巧的經典範例：排序的關鍵
 * 不是原始花費本身，而是「兩個選項的花費差距」）：
 * 1. 對每個人，計算 `costA - costB`（去 A 比去 B 貴多少，可能是負的，
 *    代表去 A 反而比較便宜）。
 * 2. 依照這個差距由小到大排序：差距越小（甚至是負的）代表「這個人去
 *    A 相對划算」，應該優先分去 A；差距越大代表「這個人去 B 相對
 *    划算」，應該分去 B。
 * 3. 排序後，直接把前 n 個人分去 A 市（用 costA），後 n 個人分去 B
 *    市（用 costB）。
 * 4. 貪心的正確性：這個排序方式保證了「每個人都被分到對他來說相對
 *    更划算的城市」，而且因為排序後前後兩半剛好各佔一半，天然滿足
 *    「一半去 A、一半去 B」的數量限制，不需要額外調整。
 */
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size() / 2;
        sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[0] - a[1]) < (b[0] - b[1]);
        });
        int total = 0;
        for (int i = 0; i < (int)costs.size(); ++i) {
            if (i < n) total += costs[i][0];
            else total += costs[i][1];
        }
        return total;
    }
};
