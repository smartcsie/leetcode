/**
 * 題目：253. Meeting Rooms II
 * 難度：中等 (Medium)（LeetCode Premium 題）
 * 描述：給定一組會議時間區間 intervals，每個區間是 [start, end]，求
 * 最少需要幾間會議室，才能讓所有會議都能被安排（不會有時間衝突）。
 *
 * 時間複雜度：O(N log N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （Interval Scheduling，經典的「開始時間 / 結束時間分開排序 + 雙
 * 指標掃描」技巧，不需要真的追蹤每間會議室的狀態）：
 * 1. 把所有會議的開始時間跟結束時間分別拆出來，各自獨立排序。拆開
 *    排序是這題的關鍵技巧：因為我們只關心「同一時刻有幾個會議正在
 *    進行」，不需要知道具體是哪個會議佔用哪間房間。
 * 2. 用雙指標 i（掃開始時間）、j（掃結束時間）從頭開始比較：
 *    - 如果 starts[i] < ends[j]：代表在 ends[j] 這個會議結束之前，
 *      又有一個新會議要開始，需要多一間房間（rooms++），i 前進。
 *    - 否則（starts[i] >= ends[j]）：代表有一個會議已經結束了，可以
 *      釋放一間房間（rooms--），j 前進。
 * 3. 過程中同步記錄看過的最大房間數 maxRooms，這就是任一時刻「同時
 *    進行的會議數」的最大值，也就是答案。
 * 4. 這個技巧本質上跟「氣球場面掃描線」（Sweep Line）是同一種思路：
 *    把每個區間拆成「+1（開始）」「-1（結束）」兩個事件，按時間排序
 *    後掃過去，維護一個計數器，取最大值。
 */
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> starts(n), ends(n);
        for (int i = 0; i < n; ++i) {
            starts[i] = intervals[i][0];
            ends[i] = intervals[i][1];
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int rooms = 0, maxRooms = 0;
        int i = 0, j = 0;
        while (i < n) {
            if (starts[i] < ends[j]) {
                rooms++;
                i++;
            } else {
                rooms--;
                j++;
            }
            maxRooms = max(maxRooms, rooms);
        }
        return maxRooms;
    }
};
