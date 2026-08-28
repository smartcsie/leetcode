/**
 * 題目：1925. Count Square Sum Triples
 * 難度：待補充
 * 描述：計算滿足 1 <= a, b, c <= n 且 a^2 + b^2 = c^2 的有序三元組 (a, b, c) 的數量。
 *
 * 時間複雜度：O(N^2)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 使用雙層迴圈枚舉所有可能的 a 和 b（其中 b 從 a 開始枚舉，減少重複）。
 * 2. 計算 c^2 = a^2 + b^2。
 * 3. 利用 sqrt 計算出 c 的整數近似值，並檢查鄰近候選值（避免浮點數誤差）。
 * 4. 若 (a, b, c) 合法且 c <= n，則根據 a 和 b 是否相等來計數（若 a == b 加 1，否則加 2 算對稱）。
 */

class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        unordered_set<int> squared;
        for (int i = 1; i <= n; ++i)
            squared.insert(i * i);
        for (const int a : squared)
            for (const int b : squared)
                if (squared.contains(a + b)) ++ans;
        return ans;
    }
};
