/**
 * 題目：496. Next Greater Element I (下一個更大元素 I)
 * 難度：簡單 (Easy)
 * 描述：在 nums2 中找出每個元素的下一個更大元素，並根據 nums1 的查詢回傳結果。
 * * 時間複雜度：O(N + M) - N 為 nums2 長度，M 為 nums1 長度。
 * 空間複雜度：O(N) - 雜湊表與堆疊的空間開銷。
 */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> nextGreaterMap;
        
        // 從右往左遍歷，維護一個單調遞減堆疊
        for (int i = nums2.size() - 1; i >= 0; --i) {
            int cur = nums2[i];
            
            // 彈出所有小於等於當前值的元素，保持堆疊單調遞減
            while (!st.empty() && st.top() <= cur) {
                st.pop();
            }
            
            // 若堆疊為空，代表右側無更大元素；否則堆疊頂端即為下一個更大值
            nextGreaterMap[cur] = st.empty() ? -1 : st.top();
            
            st.push(cur);
        }
        
        // 根據 nums1 的查詢對應結果
        vector<int> res;
        res.reserve(nums1.size());
        for (int num : nums1) {
            res.push_back(nextGreaterMap[num]);
        }
        
        return res;
    }
};
