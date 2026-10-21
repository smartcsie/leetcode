/**
 * 題目：160. Intersection of Two Linked Lists
 * 難度：Easy
 * 時間複雜度：O(M + N)
 * 空間複雜度：O(M + N)
 * 分類主題：linked-list
 *
 * 解法說明：
 * 兩條鏈表若相交，相交點之後的節點會完全共用（是同一批節點，不只是值相同）。
 * 因此把兩條鏈表分別壓進 stack，從尾端開始往回比對，
 * 尾端連續相同的節點就是共用部分，最後一個相同的節點即為相交起點。
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> st1, st2;

        // 把 A 鏈表所有節點由頭到尾壓入 stack（top 會是 A 的尾端）
        ListNode * cur = headA;
        while(cur) {
            st1.push(cur);
            cur = cur->next;
        }

        // 同樣處理 B 鏈表
        cur = headB;
        while(cur) {
            st2.push(cur);
            cur = cur->next;
        }
        
        // 從尾端往回比對：比較的是「節點指標」而非節點值
        // 只要兩邊 top 是同一個節點，就代表還在共用段內，持續記錄並彈出
        // 一旦不同（或任一 stack 空了）就代表已退到共用段的起點之前
        ListNode *intersection = nullptr;
        while(!st1.empty() && !st2.empty() && st1.top() == st2.top()) {
            intersection = st1.top();  // 目前已知的最前面一個共用節點
            st1.pop();
            st2.pop();
        }

        // 若尾端就不同（沒有共用段），intersection 維持 nullptr，代表不相交
        return intersection;
    }
};