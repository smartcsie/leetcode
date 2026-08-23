/**
 * 題目：1167. Minimum Cost to Connect Sticks
 * 難度：中等 (Medium)
 * 描述：給定一組木棍長度 sticks，每次可以把任兩根木棍接起來，花費是
 * 兩根長度之和，接完之後變成一根新木棍（長度是原本兩根之和），求把
 * 所有木棍接成一根的最小總花費。
 *
 * 時間複雜度：O(N log N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （Huffman-Type Greedy 的教科書級原型題，這個分類的名字就是從這裡
 * 來的——霍夫曼編碼的核心邏輯就是「每次合併最小的兩堆」）：
 * 1. 用一個 min-heap 存所有木棍長度。
 * 2. 貪心策略：每次都取出「目前最短的兩根」木棍接起來。這樣做的
 *    原因是：每根木棍最終都會被計入花費「好幾次」（每接一次就多算
 *    一次），越短的木棍如果越晚被接，之後每次接它都要花更多次數的
 *    累加成本；讓最短的木棍儘早合併、儘早「變成別人的一部分」，可以
 *    讓它被重複計算的次數降到最低，這正是霍夫曼編碼「頻率越低的符號
 *    編碼樹深度越深（合併越早）」背後的相同原理。
 * 3. 把接起來的新長度（cost = a + b）累加進總花費，並把這根新木棍
 *    放回 heap 裡繼續參與後續的合併。
 * 4. 重複直到 heap 裡只剩一根木棍為止，累計的總花費就是答案。
 */
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> minHeap(sticks.begin(), sticks.end());
        int total = 0;
        while (minHeap.size() > 1) {
            int a = minHeap.top(); minHeap.pop();
            int b = minHeap.top(); minHeap.pop();
            int cost = a + b;
            total += cost;
            minHeap.push(cost);
        }
        return total;
    }
};
