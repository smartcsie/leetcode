/**
 * 題目：930. Binary Subarrays With Sum
 * 難度：中等 (Medium)
 * 描述：計算二進位陣列中和等於 goal 的子陣列個數。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （前綴和 + 雙層迴圈）：
 * 計算前綴和，對每個 [i,j] 區間檢查 prefix[j+1] - prefix[i] == goal。
 */
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for(int i = 0 ; i < n ;i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int ans = 0;
        for(int i = 0 ; i < n ;i++) {
            for(int j = i ; j < n ;j++) {
                if(prefix[j + 1] - prefix[i] == goal) ans++;
            }
        }
        return ans;
    }
};