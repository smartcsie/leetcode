/**
 * 題目：1529. Minimum Suffix Flips
 * 難度：中等 (Medium)
 * 描述：求將全 0 字串變為目標字串所需的最少後綴翻轉次數。
 * 優化重點：
 * 1. 狀態機思維：透過記錄 current 狀態，將 O(N^2) 的模擬簡化為 O(N) 的計數。
 * 2. 極致空間：僅使用 O(1) 的額外空間。
 *
 * 時間複雜度：O(N) - 單次遍歷，狀態機追蹤需要翻轉的位置。
 * 空間複雜度：O(1) - 僅使用常數空間。
 */

class Solution {
public:
    int minFlips(std::string target) {
        int flips = 0;
        char curCh = '0';
        for(const char& c : target) {
            if(c != curCh) {
                flips++;
                curCh = c;
            }
        }
        return flips;
    }
};
