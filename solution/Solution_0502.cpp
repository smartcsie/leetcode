/**
 * 題目：502. IPO
 * 難度：困難 (Hard)
 * 描述：給定初始資金 w，最多可以做 k 個專案，每個專案有需要的最低
 * 資金 capital[i] 和完成後能拿到的利潤 profits[i]（資金不夠就不能做
 * 這個專案，但做完之後利潤會加進資金裡）。求做完最多 k 個專案之後，
 * 能達到的最大資金。
 *
 * 時間複雜度：O(N log N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （Priority Queue Greedy 的經典範例，跟 871 的「先納入候選、需要時
 * 才挑最好的」是同一種模式，只是這裡的候選條件是「資金門檻夠不夠」）：
 * 1. 把專案依照「需要的資金門檻」由小到大排序。
 * 2. 用一個 max-heap 存「目前資金能負擔、還沒被選過」的專案利潤。
 * 3. 重複 k 次：先把「目前資金 w 能負擔的所有專案」都丟進 heap（隨著
 *    w 增加，能負擔的專案會越來越多，這也是為什麼要放進候選池慢慢
 *    累積，而不是每次都重新掃描一遍）；如果 heap 是空的，代表沒有
 *    能做的專案了，直接結束；否則貪心選 heap 裡利潤最高的那個，加進
 *    資金 w。
 * 4. 答案是做完最多 k 輪之後的最終資金 w。
 */
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> projects(n);
        for (int i = 0; i < n; ++i) projects[i] = {capital[i], profits[i]};
        sort(projects.begin(), projects.end());

        priority_queue<int> maxHeap;
        int idx = 0;
        for (int round = 0; round < k; ++round) {
            while (idx < n && projects[idx].first <= w) {
                maxHeap.push(projects[idx].second);
                idx++;
            }
            if (maxHeap.empty()) break;
            w += maxHeap.top();
            maxHeap.pop();
        }
        return w;
    }
};
