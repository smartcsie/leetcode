/**
 * 題目：1394. Find Lucky Integer in an Array (找出陣列中的幸運數)
 * 難度：簡單 (Easy)
 * 描述：幸運數是指在陣列中出現次數等於其數值的整數。找出最大的幸運數。
 *
 * 時間複雜度：O(N) - 遍歷陣列一次，加上對計數陣列的掃描。
 * 空間複雜度：O(1) - 陣列大小為 501，為固定常數。
 *
 * 解法思路：
 * 1. 使用固定大小陣列統計頻率，比 unordered_map 快且記憶體更連續。
 * 2. 從最大數值開始反向遍歷，確保第一個匹配到的就是「最大」的幸運數。
 */

#include <vector>

using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> counts(501, 0);
        for(const int& x : arr) {
            counts[x]++;
        }
        for(int i = 500; i >= 1; i--) {
            if(counts[i] == i) return i;
        }
        return -1;
    }
};
