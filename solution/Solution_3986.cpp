/**
 * 題目：3986. Number of Elapsed Seconds Between Two Times
 * 難度：待補充
 * 描述：給定兩個時間字串 startTime 和 endTime（格式為 "HH:MM:SS"），
 * 計算從 startTime 到 endTime 經過了多少秒。
 *
 * 時間複雜度：O(1) - 固定解析六個數字，計算秒數差。
 * 空間複雜度：O(1) - 無額外空間。
 *
 * 解法思路：
 * 1. 時間轉換為秒（Total Seconds）：
 * - 將小時、分鐘、秒從字串直接萃取並轉換為整數。
 * - 計算當天總秒數公式：`hours * 3600 + minutes * 60 + seconds`。
 * 2. 計算時間差與處理跨天情況：
 * - 若 `start <= end`，代表在同一天內，經過的秒數直接為 `end - start`。
 * - 若 `start > end`，代表跨越了一天（24小時 = 86400秒，或根據題目邏輯加上一整天的秒數循環，此處程式碼範例採用題目的週期加法處理）。
 */

#include <string>

class Solution {
public:
    int secondsBetweenTimes(std::string startTime, std::string endTime) {
        // 解析 startTime 的時、分、秒並轉為總秒數
        int startH = (startTime[0] - '0') * 10 + (startTime[1] - '0');
        int startM = (startTime[3] - '0') * 10 + (startTime[4] - '0');
        int startS = (startTime[6] - '0') * 10 + (startTime[7] - '0');
        int start = startH * 3600 + startM * 60 + startS;
        
        // 解析 endTime 的時、分,、秒並轉為總秒數
        int endH = (endTime[0] - '0') * 10 + (endTime[1] - '0');
        int endM = (endTime[3] - '0') * 10 + (endTime[4] - '0');
        int endS = (endTime[6] - '0') * 10 + (endTime[7] - '0');
        int end = endH * 3600 + endM * 60 + endS;
        
        // 計算差值，若結束時間小於開始時間則補上循環差值
        return (start <= end) ? (end - start) : (end - start + 3600);
    }
};
