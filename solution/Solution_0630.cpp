/**
 * 題目：630. Course Schedule III
 * 難度：困難 (Hard)
 * 描述：給定一組課程 courses，courses[i] = [duration, lastDay]，一次
 * 只能修一門課，修完才能修下一門。求最多能修完幾門課（每門課都要在
 * lastDay 之前修完）。
 *
 * 時間複雜度：O(N log N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （Deadline Scheduling + 「反悔」貪心，這題的關鍵技巧是：先盡量多
 * 選，選不下的時候不是直接放棄，而是回頭「淘汰」已選裡最耗時的那個，
 * 用時長換取空間，讓後面時間更緊迫的課程也有機會排進來）：
 * 1. 先照截止日期（lastDay）由小到大排序。優先處理「越早截止」的
 *    課程，是這類排程問題的標準切入角度。
 * 2. 用一個 max-heap 存「目前已經排進課表的課程時長」，並累計目前
 *    總花費時間 time。
 * 3. 對每一門課，先假設「選它」：time += duration，把 duration 丟進
 *    heap。
 * 4. 如果選了之後 time 超過這門課的截止日（代表課表塞不下），不是
 *    直接跳過這門課，而是**反悔**：從 heap 裡彈出「目前選過的課裡
 *    耗時最長的」，把它的時間扣掉。因為目前這門課的截止日是目前為止
 *    看過最晚的（排序保證），用「耗時最長的課」換成「目前這門課」
 *    （或維持原狀，如果最長的剛好就是目前這門），courses 數量不變，
 *    但騰出來的時間更充裕，對後面還沒處理的課更有利。
 * 5. 最後 heap 裡剩下的課程數量，就是最多能修完的課程數。
 */
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        priority_queue<int> maxHeap;
        long long time = 0;
        for (auto& c : courses) {
            int duration = c[0], deadline = c[1];
            time += duration;
            maxHeap.push(duration);
            if (time > deadline) {
                time -= maxHeap.top();
                maxHeap.pop();
            }
        }
        return maxHeap.size();
    }
};
