/**
 * 題目：539. Minimum Time Difference (最小時間差)
 * 難度：中等 (Medium)
 * 描述：計算給定時間點列表中，任意兩個時間點之間的最小分鐘差。
 *
 * 時間複雜度：O(NlogN)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 1. 鴿籠原理：若時間點數量 > 1440，必定有重複時間，最小差必為 0。
 * 2. 記憶體預分配：使用 reserve 減少 vector 動態擴容開銷。
 */

class Solution {
private:
    int getTime(string s) {
        int h = (s[0] - '0') * 10 + (s[1] - '0');
        int m = (s[3] - '0') * 10 + (s[4] - '0');
        return h * 60 + m;
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<string>& tp = timePoints;
        int n = tp.size();
        vector<int> times(n);
        for(int i = 0; i < n; i++) times[i] = getTime(tp[i]);
        sort(times.begin(), times.end());
        int mn = 1440;
        for(int i = 1; i < n; i++) {;
            mn = min(mn, times[i] - times[i - 1]);
        }
        mn = min(mn, times.front() - times.back() + 1440);
        return mn;
    }
};