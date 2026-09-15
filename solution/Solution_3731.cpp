/**
 * 題目：3731. Find Missing Elements (找出缺失元素)
 * 難度：簡單 (Easy)
 * 描述：在陣列的最小值與最大值之間，找出所有未出現過的整數。
 *
 * 時間複雜度：O(N+K)
 * 空間複雜度：O(K)
 *
 * 解法思路：
 * 1. 防禦性程式設計：加入空陣列判斷以避免未定義行為 (Segmentation Fault)。
 * 2. 空間最佳化：確保標記容器大小適中，避免無效記憶體開銷。
 */

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        vector<bool> seen(101, false);
        ans.reserve(nums.size());
        int mn = 101, mx = 0;
        for(const int x : nums) {
            seen[x] = true;
            mn = min(mn, x);
            mx = max(mx, x);
        }
        for(int i = mn; i <= mx;i++) {
            if(!seen[i]) ans.push_back(i);
        }
        return ans;
    }
};
