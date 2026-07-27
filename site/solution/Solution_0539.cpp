/**
 * 題目：539. Minimum Time Difference (最小時間差)
 * 難度：中等 (Medium)
 * 描述：計算給定時間點列表中，任意兩個時間點之間的最小分鐘差。
 * * 時間複雜度：O(N log N) - 主要開銷在於排序。
 * 空間複雜度：O(N) - 儲存轉換後的分鐘數。
 * * 優化思路：
 * 1. 鴿籠原理：若時間點數量 > 1440，必定有重複時間，最小差必為 0。
 * 2. 記憶體預分配：使用 reserve 減少 vector 動態擴容開銷。
 */

class Solution {
private:
    int timeToMin(const string& time) {
        // 利用直接運算取代 stoi，提升執行效率
        return ((time[0] - '0') * 10 + (time[1] - '0')) * 60 + 
                (time[3] - '0') * 10 + (time[4] - '0');
    }

public:
    int findMinDifference(vector<string>& timePoints) {
        // 1. 鴿籠原理優化：一天只有 1440 分鐘，若輸入超過 1440 個點，必有重複
        if (timePoints.size() > 1440) return 0;
        
        vector<int> minutes;
        minutes.reserve(timePoints.size());
        
        for (const string& time : timePoints) {
            minutes.push_back(timeToMin(time));
        }
        
        sort(minutes.begin(), minutes.end());
        
        int minDiff = INT_MAX;
        int n = static_cast<int>(minutes.size());
        
        // 2. 遍歷比較相鄰時間差
        for (int i = 0; i < n - 1; ++i) {
            minDiff = min(minDiff, minutes[i + 1] - minutes[i]);
        }
        
        // 3. 處理跨午夜情況：比較首尾差值與 1440 - 差值
        return min(minDiff, 1440 - (minutes.back() - minutes.front()));
    }
};
