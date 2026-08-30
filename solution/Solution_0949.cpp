/**
 * 題目：949. Largest Time for Given Digits
 * 難度：中等 (Medium)
 * 描述：使用給定的 4 個數字，組成最大的 24 小時制時間（HH:MM）。
 * 優化重點：
 * 1. 窮舉全排列：利用 std::next_permutation 遍歷所有 24 種組合。
 * 2. 條件過濾：確保 hour < 24 且 minute < 60。
 * 3. 狀態記錄：維護當前找到的最大小時與分鐘。
 *
 * 時間複雜度：O(1)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    std::string largestTimeFromDigits(std::vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int maxTime = -1;
        do {
            int h = arr[0] * 10 + arr[1];
            int m = arr[2] * 10 + arr[3];
            if(h < 24 && m < 60) {
                maxTime = max(maxTime, h * 60 + m);
            }
        } while(next_permutation(arr.begin(), arr.end()));
        if(maxTime == -1) return "";
        char buf[6];
        snprintf(buf, sizeof(buf), "%02d:%02d", maxTime / 60, maxTime % 60);
        return string(buf);
    }
};
