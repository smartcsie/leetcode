/**
 * 題目：1046. Last Stone Weight (最後一顆石頭的重量)
 * 難度：簡單 (Easy)
 * 描述：每次選取兩顆最重的石頭進行碰撞，若重量相等則皆粉碎，不相等則餘數留回堆中。
 * * 時間複雜度：O(N log N) - 建堆 O(N)，每次彈出/壓入 O(log N)。
 * 空間複雜度：O(N) - 儲存所有石頭的重量。
 * * 優化思路：
 * 利用 priority_queue 的建構子 `priority_queue<int>(stones.begin(), stones.end())`，
 * 這比逐一呼叫 `push` 更快，因為這會觸發線性時間的建堆演算法。
 */


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // 利用建構子直接初始化，比迴圈 push 更高效
        priority_queue<int> pq(stones.begin(), stones.end());
        
        while (pq.size() > 1) {
            int y = pq.top(); pq.pop(); // 最重的石頭
            int x = pq.top(); pq.pop(); // 次重的石頭
            
            // 若兩者重量不同，將差值壓回堆中
            if (x != y) {
                pq.push(y - x);
            }
        }
        
        // 若堆為空回傳 0，否則回傳剩下的石頭重量
        return pq.empty() ? 0 : pq.top();
    }
};
