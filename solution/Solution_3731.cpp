// 題目：3731. Find Missing Elements
// 難度：Easy
// 時間複雜度：O(n + R)，R = max - min（值域最多 100，實際可視為 O(1)）
// 空間複雜度：O(1)（固定 101 bits 的 bitset，不含回傳答案）
// 分類主題：array / hash-table
// 技巧：bitset 當存在表（值域小）、minmax_element 一次找最小與最大值

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        // 題目限制 1 <= nums[i] <= 100，用 101 bits 即可直接以數值當索引
        // bitset 預設全為 0，seen[v] == 1 表示 v 出現在 nums 中
        bitset<101> seen;
        for(const int& x : nums) seen.set(x);

        // 一次掃描同時取得最小值與最大值（結構化綁定取得兩個迭代器）
        auto [minIt, maxIt] = minmax_element(nums.begin(), nums.end());

        vector<int> ans;
        // 只檢查 (min, max) 範圍內缺的數字；
        // min 與 max 本身一定在 nums 裡，所以 x < max 就夠，不會漏
        for(int x = *minIt; x < *maxIt; x++) {
            if(!seen.test(x)) ans.push_back(x);   // 沒出現過就是缺少的元素
        }
        // 因為由小到大掃描，答案天然是遞增排序，符合題目要求
        return ans;
    }
};