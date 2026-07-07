/**
 * 題目：2231. Largest Number After Digit Swaps by Parity
 * 難度：簡單 (Easy)
 * 描述：允許交換 num 中奇偶性相同的數位任意次，求交換後能得到的最大整數。
 *
 * 核心概念：
 * - 奇偶性相同的數位可以任意重排，奇偶性不同則位置固定不變。
 * - 依奇偶性將字元分成兩組，各自由大到小排序。
 * - 依照原字串每個位置的奇偶性，貪心地依序填入該組中最大的字元。
 */

class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        vector<vector<char>> buckets(2);
        for(const char& c : s) {
            buckets[c & 1].push_back(c);
        }
        sort(buckets[0].begin(), buckets[0].end(), greater<>());
        sort(buckets[1].begin(), buckets[1].end(), greater<>());

        vector<int> index(2, 0);
        for(char& c : s) {
            c = buckets[c & 1][index[c & 1]++];
        }
        return stoi(s);
    }
};
