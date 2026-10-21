/**
 * 題目：160. Intersection of Two Linked Lists
 * 難度：Easy
 * 時間複雜度：O(M + N)
 * 空間複雜度：O(M)
 * 分類主題：hash-table-existence
 *
 * 解法說明：
 * 若兩條鏈表相交，相交點之後的節點是「同一批節點」（指標位址相同）。
 * 先把 A 鏈表的所有節點指標存進 hash set，
 * 再走訪 B 鏈表，第一個出現在 set 裡的節點就是相交起點。
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 存的是「節點指標」而非節點值，
        // 因為值相同的節點不代表是同一個節點，只有位址相同才算相交
        unordered_set<ListNode*> seen;

        // 走訪 A 鏈表，把每個節點記錄下來
        ListNode * cur = headA;
        while(cur) {
            seen.insert(cur);
            cur = cur->next;
        }

        // 走訪 B 鏈表，由頭開始檢查
        // 第一個在 set 裡找到的節點，就是 B 這邊最早進入共用段的節點，即相交起點
        cur = headB;
        while(cur) {
            if(seen.contains(cur)) return cur;  // contains 為 C++20 語法
            cur = cur->next;
        }

        // B 鏈表整條都沒有節點出現在 A 裡 → 不相交
        return nullptr;
    }
};