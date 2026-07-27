/**
 * 題目：724. Find Pivot Index (尋找樞紐索引)
 * 難度：簡單 (Easy)
 * 描述：找到一個索引，使其左側元素總和等於右側元素總和。
 * * 時間複雜度：O(N) - 兩次遍歷（一次求和，一次檢查）。
 * 空間複雜度：O(1) - 僅使用幾個整數變數。
 * * 優化思路：
 * 左側總和 + 當前值 + 右側總和 = 總和。
 * 若左側總和 == 右側總和，則 pivot index 滿足條件。
 */

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        for(int i = 0; i < n; i++) {
            if(prefix[i] == prefix[n] - prefix[i + 1]) return i;
        }
        return -1;
    }
};
