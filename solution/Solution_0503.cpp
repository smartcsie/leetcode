/**
 * 題目：503. Next Greater Element II (下一個更大元素 II)
 * 難度：中等 (Medium)
 * 描述：在循環陣列中，找出每個元素的下一個更大元素。
 * * 時間複雜度：O(N) - 遍歷 2N 次，每個元素最多進出堆疊一次。
 * 空間複雜度：O(N) - 堆疊儲存元素。
 * * 解法思路：
 * 透過 i % n 的模運算，在不真的複製陣列的前提下，模擬陣列的循環狀態。
 */

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> stk;

        // 循環陣列的處理技巧：遍歷兩次陣列 (0 到 2n-1)
        // 第一次遍歷建立基礎，第二次遍歷填補循環後的數值
        for (int i = 2 * n - 1; i >= 0; --i) {
            int cur = nums[i % n];
            
            // 維護單調遞減堆疊：彈出小於等於當前值的元素
            while (!stk.empty() && stk.top() <= cur) {
                stk.pop();
            }
            
            // 若堆疊非空，堆疊頂端即為右側最近的更大元素
            if (!stk.empty()) {
                ans[i % n] = stk.top();
            }
            
            stk.push(cur);
        }
        
        return ans;
    }
};
