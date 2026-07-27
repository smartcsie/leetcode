/**
 * 題目：2433. Find The Original Array of Prefix Xor (找出前綴異或的原陣列)
 * 難度：中等 (Medium)
 * 描述：給你一個長度為 n 的整數陣列 pref。找出並返回滿足以下條件的原陣列 arr：
 * pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i]
 *
 * 時間複雜度：O(n) - 僅需對 pref 陣列進行一次從頭到尾的線性掃描，每個元素的還原皆為常數時間的硬體 XOR 運算。
 * 空間複雜度：O(n) - 建立大小為 n 的 ans 陣列來儲存還原後的原始陣列（若計入回傳值；若改採原地修改則可降至 O(1)）。
 *
 * 解法思路：
 * 1. XOR 運算的自我反轉性質：
 * - 在位元運算中，XOR 具備一個非常重要的特性：若 A ^ B = C，則 A ^ C = B。
 * 2. 推導還原公式：
 * - 根據題目定義，pref[i-1] = arr[0] ^ ... ^ arr[i-1]，而 pref[i] = arr[0] ^ ... ^ arr[i-1] ^ arr[i]。
 * - 將兩式進行 XOR 運算可得：pref[i - 1] ^ pref[i] = arr[i]。
 * 3. 實作步驟：
 * - 第一個元素直接對應 pref[0]（即 ans[0] = pref[0]）。
 * - 從索引 1 開始，透過 ans[i] = pref[i - 1] ^ pref[i] 依序還原後續元素。
 */

class Solution {
public:
    std::vector<int> findArray(std::vector<int>& pref) {
        int n = pref.size();
        std::vector<int> ans(n, 0);
        
        // 第一個元素直接對應 pref[0]
        ans[0] = pref[0];
        
        // 利用 XOR 的反轉性質還原後續元素
        for (int i = 1; i < n; i++) {
            ans[i] = pref[i - 1] ^ pref[i];
        }
        
        return ans;
    }
};
