/**
 * 題目：871. Minimum Number of Refueling Stops
 * 難度：困難 (Hard)
 * 描述：車子從位置 0 出發，油箱初始油量 startFuel，要開到 target。
 * 沿途有加油站 stations[i] = [position, fuel]，求最少需要停靠幾個
 * 加油站（不能停在半路沒油，如果永遠到不了回傳 -1）。
 *
 * 時間複雜度：O(N log N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （Priority Queue Greedy：邊走邊把「路過的加油站」丟進候選池，
 * 真的沒油了才「回頭」用候選池裡最大的那桶油，這個「先經過、需要時
 * 才反悔挑最大」的模式是這題精妙的地方）：
 * 1. 用一個 max-heap 存「已經路過、但還沒使用」的加油站油量。
 * 2. 只要目前油量 fuel 還不夠到達 target：
 *    - 先把「目前油量範圍內能到達」的所有加油站油量都丟進 heap
 *      （代表這些加油站已經路過了，可以隨時回頭取用）。
 *    - 如果 heap 是空的（沒有任何加油站可以用），代表卡住了，
 *      回傳 -1。
 *    - 否則貪心地選 heap 裡油量最多的那個加進油箱（stops++），這樣
 *      能讓每次加油都「賺最多」，需要停靠的次數自然最少。
 * 3. 這個技巧的巧妙之處：不用事先決定「要不要在這一站加油」，而是
 *    先把所有路過的加油站都當作候選，等真的需要加油時，才回頭挑
 *    「候選裡最好的」，等價於已經走過的路上「隨插即用」，這樣選出來
 *    的一定是全局最優（因為候選池只會越來越大，選擇永遠不會變差）。
 */
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> maxHeap;
        int stops = 0;
        long long fuel = startFuel;
        int i = 0;
        int n = stations.size();

        while (fuel < target) {
            while (i < n && stations[i][0] <= fuel) {
                maxHeap.push(stations[i][1]);
                i++;
            }
            if (maxHeap.empty()) return -1;
            fuel += maxHeap.top();
            maxHeap.pop();
            stops++;
        }
        return stops;
    }
};
