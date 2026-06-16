/**
 * 題目：2574. Left and Right Sum Differences
 * 修正點：
 * 1. 修改 right 計算公式，使用 prefix[n] 取得總和。
 * 2. 修正迴圈範圍為 0 到 n-1，確保每個位置都計算到。
 */

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n + 1, 0);
        for(int i = 0; i < n; i++) {
            prefix[i + 1] = nums[i] + prefix[i]; 
        }

        vector<int> res;
        res.reserve(n);

        for(int i = 0; i < n; i++) { 
            int left = prefix[i];
            int right =  prefix[n] - prefix[i + 1];
            res.push_back(abs(right - left));
        }
        
        return res;
        
    }
};
