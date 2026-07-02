/**
 * 題目：89. Gray Code (格雷碼)
 * 難度：中等 (Medium)
 * 描述：生成一個 n 位的格雷碼序列，使得序列中相鄰兩數僅有一位元不同。
 * * 時間複雜度：O(2^N)，需要生成 2^N 個數。
 * 空間複雜度：O(1) (排除回傳陣列所需的 O(2^N) 空間)。
 * * 優化思路：
 * 1. 使用 reserve() 預先配置記憶體，避免動態擴充導致的效能損耗。
 */

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for (int i = 0; i < (1 << n); i++) {
            res.push_back(i ^ (i >> 1));
        }
        return res;
    }
};
