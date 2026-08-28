/**
 * 題目：1019. Next Greater Node In Linked List (鏈結串列中的下一個更大節點)
 * 難度：中等 (Medium)
 * 描述：給定鏈結串列 head，對每個節點，找出其後面第一個值更大的節點值，
 *       若不存在則該位置回傳 0，最終以陣列形式回傳每個節點對應的結果。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 1. 單調遞減堆疊 (Monotonic Decreasing Stack)：
 *    - 用 stack 存放「尚未找到下一個更大值」的節點索引，堆疊由底到頂維持數值遞減的特性。
 * 2. 巧妙運用答案陣列暫存原始值：
 *    - 先把目前節點值暫存到 ans[i]（此時 ans[i] 還沒被賦予最終答案），
 *      這樣堆疊裡的索引可以直接透過 ans[st.top()] 取得該位置原本的節點值來比較。
 * 3. 找到更大值時彈出並更新：
 *    - 當目前節點值大於堆疊頂端索引所暫存的原始值時，代表找到了下一個更大節點，
 *      將該索引的 ans 值更新為目前節點值，並將索引彈出堆疊。
 * 4. 處理堆疊中剩餘的索引：
 *    - 走訪完整個鏈結串列後，堆疊中剩下的索引代表「找不到下一個更大值」，
 *      將這些位置的 ans 值統一設回 0。
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        int n = 0;
        for (ListNode* cur = head; cur; cur = cur->next) n++;
        vector<int> ans(n, 0);

        stack<int> st;  // 存 index
        int i = 0;
        for (ListNode* cur = head; cur; cur = cur->next, i++) {
            while (!st.empty() && cur->val > ans[st.top()]) {
                ans[st.top()] = cur->val;  // 找到更大值，更新對應位置
                st.pop();
            }
            ans[i] = cur->val;  // 先把當前值存入
            st.push(i);
        }

        // stack 中剩餘的 index，沒有更大節點，保持 0
        while (!st.empty()) {
            ans[st.top()] = 0;
            st.pop();
        }

        return ans;
    }
};
