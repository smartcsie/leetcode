/**
 * 題目：1304. Find N Unique Integers Sum up to Zero
 * 難度：簡單 (Easy)
 * 描述：產生 n 個唯一的整數，使它們的總和為 0。
 * 優化重點：
 * 1. 使用 reserve() 預先分配記憶體，避免動態擴充開銷。
 * 2. 使用位元運算 `n & 1` 檢查奇偶性，語法簡潔且效率高。
 * 3. 邏輯區分偶數對配對與奇數中間值補 0。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    vector<int> sumZero(int n) {
        if(n == 1) return {0};
        vector<int> ans(n - 1);
        iota(ans.begin(), ans.end(), 1);
        ans.push_back(-(n * (n - 1) / 2));
        return ans;
    }
};
