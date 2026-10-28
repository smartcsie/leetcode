/**
 * 題目：3759. Count Elements With at Least K Greater Values
 * 難度：Medium
 * 時間複雜度：O(N)，nth_element 平均 O(N)
 * 空間複雜度：O(1)
 * 分類主題：quick-select
 *
 * 解法說明：
 * 令 v 為「第 k 大的值」（升序排好的第 n-k 個位置）：
 *   - 嚴格小於 v 的元素：v 以及 v 右邊至少 k 個元素都比它大 → 符合
 *   - 大於或等於 v 的元素：嚴格比它大的元素最多只有 k-1 個 → 不符合
 * 所以答案 = 嚴格小於 v 的元素個數。
 * 不需要完整排序，只要用 nth_element（quick select）找出 v 即可。
 */
class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();

        // k == 0：不需要有更大的元素，每個元素都符合
        if(k == 0) return n;

        // 每個元素最多只有 n-1 個其他元素，n <= k 時不可能湊到 k 個更大的
        if(n <= k) return 0;

        // it 指向升序排好後的第 n-k 個位置，也就是第 k 大的元素
        auto it = nums.begin() + (n - k);

        // quick select：只保證 it 位置的值正確，左邊都 <= *it，右邊都 >= *it
        // 其餘部分不保證有序，平均 O(N)
        nth_element(nums.begin(), it, nums.end());
        int v = *it;  // 第 k 大的值（門檻）

        // nth_element 不保證其他部分有序，所以不能直接用位置當答案
        // 左邊可能有等於 v 的元素（重複值），要用 count_if 明確數嚴格小於 v 的個數
        return count_if(nums.begin(), nums.end(), [v](int x) { return x < v; });
    }
};
