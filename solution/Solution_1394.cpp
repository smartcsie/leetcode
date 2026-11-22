/**
 * 題目：1394. Find Lucky Integer in an Array (找出陣列中的幸運數)
 * 難度：簡單 (Easy)
 * 描述：幸運數是指在陣列中出現次數等於其數值的整數。找出最大的幸運數。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 使用固定大小陣列統計頻率，比 unordered_map 快且記憶體更連續。
 * 2. 從最大數值開始反向遍歷，確保第一個匹配到的就是「最大」的幸運數。
 */

class Solution {
public:
    int findLucky(vector<int>& arr) {
        array<uint16_t, 501> counts{};
        for(const int& x : arr) counts[x]++;
        for(int x = 500; x >= 1; x--) {
            if(counts[x] == x) return x;
        }
        return -1;
    }
};


