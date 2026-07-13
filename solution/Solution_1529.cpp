/**
 * 題目：1529. Minimum Suffix Flips
 * 難度：中等 (Medium)
 * 描述：求將全 0 字串變為目標字串所需的最少後綴翻轉次數。
 * * 優化重點：
 * 1. 狀態機思維：透過記錄 current 狀態，將 O(N^2) 的模擬簡化為 O(N) 的計數。
 * 2. 極致空間：僅使用 O(1) 的額外空間。
 */

class Solution {
public:
    int minFlips(std::string target) {
        int ops = 0;
        char current = '0'; // 初始狀態 s 為全 '0'
        
        for (char c : target) {
            // 如果目標字元與當前期待的狀態不同，則必須執行翻轉
            if (c != current) {
                ops++;
                current = c; // 狀態翻轉後，更新當前期待的狀態
            }
        }
        
        return ops;
    }
};
