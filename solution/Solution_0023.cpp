/**
 * 題目：23. Merge k Sorted Lists (合併 K 個排序鏈結串列)
 * 難度：困難 (Hard)
 * 描述：將 K 個已排序的鏈結串列合併為一個排序鏈結串列。
 * * 時間複雜度：O(N log k)，其中 N 為總節點數，k 為鏈結串列數量。
 * 空間複雜度：O(k) - 優先佇列中最多同時存在 k 個節點。
 * * 優化思路：
 * 使用 lambda 表示式定義比較規則，使代碼更簡潔，並在每次取出節點時，
 * 若該節點有下一個節點，則立即將其壓入堆中，確保堆的大小永遠不超過 k。
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 使用 lambda 定義最小堆的比較規則，直接定義在參數中
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);
        
        // 1. 初始化堆：將所有非空鏈結串列的頭節點壓入
        for (auto list : lists) {
            if (list) minHeap.push(list);
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // 2. 核心迴圈：每次取出最小節點，並加入其下一個節點
        while (!minHeap.empty()) {
            ListNode* top = minHeap.top();
            minHeap.pop();
            
            tail->next = top;
            tail = tail->next;
            
            if (top->next) {
                minHeap.push(top->next);
            }
        }
        
        return dummy.next;
    }
};
