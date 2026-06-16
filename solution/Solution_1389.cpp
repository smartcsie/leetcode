/**
 * 題目：1389. Create Target Array in the Given Order (按既定順序建立目標陣列)
 * 難度：簡單 (Easy)
 * 描述：根據給定的 nums 和 index 陣列，動態構建目標陣列。
 * * 時間複雜度：O(N^2) - 每次 insert 最壞情況需要移動 N 個元素，執行 N 次。
 * 空間複雜度：O(N) - 用於儲存最終結果。
 * * 優化思路：
 * 1. 預分配：使用 reserve 避免在插入過程中觸發多次記憶體重新配置。
 * 2. 直接操作：vector::insert 是處理此類問題最直觀且高效的方式。
 */

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int> res;
        res.reserve(n);
        for(int i = 0; i < n; i++) {
            res.insert(res.begin() + index[i], nums[i]);
        }
        return res;
    }
};
