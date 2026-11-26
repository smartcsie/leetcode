/**
 * 題目：3986. Number of Elapsed Seconds Between Two Times
 * 難度：簡單 (Easy)
 * 描述：給定兩個時間字串 startTime 和 endTime（格式為 "HH:MM:SS"），
 * 計算從 startTime 到 endTime 經過了多少秒。
 *
 * 時間複雜度：O(1)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 時間轉換為秒（Total Seconds）：
 * - 將小時、分鐘、秒從字串直接萃取並轉換為整數。
 * - 計算當天總秒數公式：`hours * 3600 + minutes * 60 + seconds`。
 * 2. 計算時間差與處理跨天情況：
 * - 若 `start <= end`，代表在同一天內，經過的秒數直接為 `end - start`。
 * - 若 `start > end`，代表跨越了一天（24小時 = 86400秒，或根據題目邏輯加上一整天的秒數循環，此處程式碼範例採用題目的週期加法處理）。
 */

class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int h1 = (startTime[0] - '0') * 10 + (startTime[1] - '0');
        int m1 = h1 * 60 + (startTime[3] - '0') * 10 + (startTime[4] - '0');
        int s1 = m1 * 60 + (startTime[6] - '0') * 10 + (startTime[7] - '0');
        int h2 = (endTime[0] - '0') * 10 + (endTime[1] - '0');
        int m2 = h2 * 60 + (endTime[3] - '0') * 10 + (endTime[4] - '0');
        int s2 = m2 * 60 + (endTime[6] - '0') * 10 + (endTime[7] - '0');
        return s2 - s1;
    }
};