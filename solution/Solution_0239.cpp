/**
 * 題目：239. Sliding Window Maximum (滑動視窗最大值)
 * 難度：困難 (Hard)
 * 描述：找出大小為 k 的滑動視窗中，每個視窗內的最大值。
 * * 時間複雜度：O(N) - 每個元素最多被 push 和 pop 進 deque 一次。
 * 空間複雜度：O(K) - 佇列中最多儲存 K 個索引。
 * * 優化思路：
 * 1. 單調佇列 (Monotonic Queue)：維護隊首為視窗內最大值的索引。
 * 2. 移除無效元素：若當前數字大於隊尾元素，則隊尾元素失去價值，直接彈出。
 * 3. 視窗滑動：若隊首索引已超出視窗範圍 [i-k+1, i]，則將其移除。
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // 存入 nums 的 index
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); ++i) {
            // 1. 維護單調遞減性：若隊尾元素小於當前元素，彈出隊尾
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            
            // 2. 移除視窗外的過期索引 (隊首索引小於 i - k + 1)
            if (dq.front() == i - k) {
                dq.pop_front();
            }
            
            // 3. 從第 k-1 個元素開始記錄答案
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
