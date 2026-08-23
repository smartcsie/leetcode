/**
 * 題目：135. Candy
 * 難度：困難 (Hard)
 * 描述：n 個小孩排成一列，每個小孩有一個評分 ratings[i]。每人至少要
 * 分到 1 顆糖，評分比左右鄰居高的小孩，糖果數必須比該鄰居多。求最少
 * 需要準備多少顆糖。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （Fractional Knapsack 分類裡的「兩次單方向掃描」貪心，因為同時
 * 滿足「比左邊鄰居高就要更多」跟「比右邊鄰居高就要更多」兩個方向的
 * 限制，一次掃描做不到，要拆成兩趟各自處理一個方向）：
 * 1. 先每人發 1 顆糖（基本盤）。
 * 2. **第一趟（由左到右）**：只考慮「跟左邊鄰居比」的限制。如果
 *    ratings[i] > ratings[i-1]，代表這個小孩至少要比左邊多 1 顆，
 *    candies[i] = candies[i-1] + 1。
 * 3. **第二趟（由右到左）**：只考慮「跟右邊鄰居比」的限制。如果
 *    ratings[i] > ratings[i+1]，代表這個小孩至少要比右邊多 1 顆，
 *    但這裡要注意：第一趟可能已經因為「左邊限制」讓 candies[i] 變得
 *    夠大了，所以要取 max(目前的 candies[i], candies[i+1] + 1)，
 *    不能直接覆蓋，否則會讓左邊限制的結果被吃掉。
 * 4. 兩趟都做完之後，每個位置的糖果數同時滿足「比左邊高的鄰居多」跟
 *    「比右邊高的鄰居多」兩個限制，加總就是答案。
 */
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) candies[i] = candies[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) candies[i] = max(candies[i], candies[i + 1] + 1);
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
