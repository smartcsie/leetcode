/**
 * 題目：1925. Count Square Sum Triples
 * 描述：計算滿足 1 <= a, b, c <= n 且 a^2 + b^2 = c^2 的有序三元組 (a, b, c) 的數量。
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
        int count = 0;
        for (int a = 1; a <= n; ++a) {
            for (int b = a; b <= n; ++b) {
                int c2 = a * a + b * b;
                int c = static_cast<int>(std::sqrt(static_cast<double>(c2)));
                
                // 為了防範浮點數運算誤差，檢查 c-1, c, c+1 三個候選數字
                for (int cand = std::max(1, c - 1); cand <= c + 1; ++cand) {
                    if ((long long)cand * cand == c2 && cand <= n) {
                        // 若 a == b，只有一種組合；若 a != b，則 (a, b, c) 與 (b, a, c) 算兩組
                        count += (a == b) ? 1 : 2;
                        break;  // 找到合法的 c 就跳出內層候選迴圈
                    }
                }
            }
        }
        return count;
    }
};
