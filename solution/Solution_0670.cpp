/**
 * 題目：670. Maximum Swap
 * 難度：中等 (Medium)
 * 描述：在最多一次交換下，求出能得到的最大數字。
 * * 優化重點：
 * 1. 預處理：使用 last_idx 陣列紀錄每個數字最後出現的位置，確保交換時能選到「最右邊」的大數。
 * 2. 貪心策略：由左至右尋找第一個能被交換以變大的高位數字。
 */

class Solution {
public:
    int maximumSwap(int num) {
        std::string s = std::to_string(num);
        int n = s.size();
        
        // 紀錄每個數字 (0-9) 最後出現的索引
        std::vector<int> last_idx(10);
        for (int i = 0; i < n; ++i) {
            last_idx[s[i] - '0'] = i;
        }
        
        // 遍歷尋找第一個可以交換以變大的位置
        for (int i = 0; i < n; ++i) {
            // 從 9 到當前數字 s[i] 檢查是否有更大的數出現在後面
            for (int d = 9; d > s[i] - '0'; --d) {
                if (last_idx[d] > i) {
                    // 執行交換，該數字位於 last_idx[d] 一定是該數字最右邊的實例
                    std::swap(s[i], s[last_idx[d]]);
                    return std::stoi(s);
                }
            }
        }
        
        return num; // 若遍歷後無法變大，則回傳原數
    }
};
