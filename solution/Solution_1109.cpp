/**
 * 題目：1109. Corporate Flight Bookings
 * 難度：中等 (Medium)
 * 描述：計算每一架航班在所有預訂請求後的總座位數。
 * 優化重點：
 * 1. 差分標記：`diff[first - 1] += seats` 與 `diff[last] -= seats`。
 * 2. 前綴和還原：透過累加差分陣列得出最終結果。
 *
 * 時間複雜度：O(N+K)
 * 空間複雜度：O(N)
 */

vector<int> diff(n + 1, 0); // 多一格避免越界判斷
    for (const auto& b : bookings) {
        diff[b[0] - 1] += b[2];  // 起點加
        diff[b[1]]     -= b[2];  // 終點後一格減
    }
    // 前綴和還原
    for (int i = 1; i < n; i++)
        diff[i] += diff[i - 1];
    diff.pop_back(); // 拿掉多的那格
    return diff;
}