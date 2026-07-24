/**
 * 題目：1375. Number of Times Binary String Is Prefix-Aligned
 * 描述：給你一個長度為 n 的二進位字串開關陣列 flips（1-indexed）。
 *       一開始所有燈泡都是關閉的（0）。在第 i 個步驟中，我們會打開編號為 flips[i] 的燈泡。
 *       請返回在整個翻轉過程中，有多少時刻所有的藍色燈泡（即從第 1 顆到當前右界）
 *       都已經被點亮了（即 Prefix-Aligned）。
 * 
 * 解法思路：
 * 1. 宣告 `ans` 記錄符合條件的次數，`mx` 記錄目前所有被翻轉過的燈泡中「最大的編號」。
 * 2. 走訪 `flips` 陣列，進行第 `i` 次操作（注意迴圈從 `0` 開始，故當前總操作次數為 `i + 1`）。
 * 3. 更新當前最大燈泡編號：`mx = max(mx, flips[i]);`。
 * 4. 根據數學性質：如果目前點亮的燈泡中「最大編號 `mx`」剛好等於「總共點亮的燈泡數量 `i + 1`」，
 *    這代表從第 1 顆到第 `mx` 顆燈泡剛好全部被點亮，中間沒有任何空隙，符合 Prefix-Aligned。
 * 5. 若符合條件則將 `ans` 加 1，迴圈結束後返回 `ans`。
 */

class Solution {
public:
    int numTimesAllBlue(std::vector<int>& flips) {
        int ans = 0;
        int mx = 0; // 記錄目前被翻轉過的燈泡最大編號
        
        for (int i = 0; i < flips.size(); ++i) {
            mx = std::max(mx, flips[i]);
            
            // 當最大編號剛好等於目前點亮的燈泡總數 (i + 1) 時，代表 1 到 mx 全亮
            if (mx == i + 1) {
                ans++;
            }
        }
        
        return ans;
    }
};
