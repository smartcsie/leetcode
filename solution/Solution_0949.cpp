/**
 * 題目：949. Largest Time for Given Digits
 * 難度：中等 (Medium)
 * 描述：使用給定的 4 個數字，組成最大的 24 小時制時間（HH:MM）。
 * * 優化重點：
 * 1. 窮舉全排列：利用 std::next_permutation 遍歷所有 24 種組合。
 * 2. 條件過濾：確保 hour < 24 且 minute < 60。
 * 3. 狀態記錄：維護當前找到的最大小時與分鐘。
 */

class Solution {
public:
    std::string largestTimeFromDigits(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        int max_time = -1; // 將 HH:MM 轉為數值 HH * 60 + MM 便於比較

        do {
            int hour = arr[0] * 10 + arr[1];
            int minute = arr[2] * 10 + arr[3];

            if (hour < 24 && minute < 60) {
                max_time = std::max(max_time, hour * 60 + minute);
            }
        } while (std::next_permutation(arr.begin(), arr.end()));

        if (max_time == -1) return "";

        // 格式化輸出
        char buf[6];
        snprintf(buf, sizeof(buf), "%02d:%02d", max_time / 60, max_time % 60);
        return std::string(buf);
    }
};
