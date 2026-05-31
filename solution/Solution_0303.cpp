/**
 * 題目：303. Range Sum Query - Immutable (區域和檢索 - 不可變)
 * 難度：簡單 (Easy)
 * 描述：計算陣列中指定區間 [left, right] 的元素總和。
 * * 時間複雜度：初始化 O(N)，查詢 O(1)。
 * 空間複雜度：O(N) - 使用前綴和陣列。
 * * 解法思路：
 * 將 prefix[i] 定義為前 i 個元素的和，則 range(left, right) = prefix[right + 1] - prefix[left]。
 */

class NumArray {
private:
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) : prefix(nums.size() + 1, 0) {
        for(int i = 0; i < nums.size(); i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }
    }
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};
