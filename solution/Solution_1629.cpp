/**
 * 題目：1629. Slowest Key
 * 難度：Easy
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 * 分類主題：array-min-max
 *
 * 解法說明：
 * 第 i 個按鍵的持續時間 = releaseTimes[i] - releaseTimes[i - 1]（第 0 個則為 releaseTimes[0]）。
 * 單趟掃描維護「目前最長持續時間」與對應的按鍵：
 *   - 持續時間更長 → 更新最長時間與按鍵
 *   - 持續時間相同 → 取字典序較大的按鍵
 */
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        // 第 0 個按鍵從時間 0 開始按，持續時間就是 releaseTimes[0]
        // 注意：變數名稱 max 會遮蔽 std::max，建議改名（如 maxDuration）
        int max = releaseTimes[0];
        char ch = keysPressed[0];

        for(int i = 1; i < keysPressed.size(); i++) {
            // 第 i 個按鍵的持續時間 = 本次放開時間 - 上次放開時間
            if(releaseTimes[i] - releaseTimes[i - 1] > max) {
                // 持續時間嚴格更長 → 更新紀錄
                max = releaseTimes[i] - releaseTimes[i - 1];
                ch = keysPressed[i];
            } else if (releaseTimes[i] - releaseTimes[i - 1] == max) {
                // 持續時間相同 → 題目要求回傳字典序最大的按鍵
                if(keysPressed[i] > ch) ch = keysPressed[i];  
            } 
            // 持續時間較短 → 不處理
        }
        return ch;
    }
};
