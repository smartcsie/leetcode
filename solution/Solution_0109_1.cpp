/*
 * 題目：109. Convert Sorted List to Binary Search Tree
 * 難度：Medium
 * 描述：給定一個依升序排序的單向鏈結串列 head，把它轉成高度平衡的二元搜尋樹（每個節點左右子樹的高度差不超過 1）。
 * 分類主題：tree-construction
 * 技巧：模擬中序走訪, 先算長度再用索引區間決定中點, 串列指標只前進不回頭
 * 時間複雜度：O(n)
 * 空間複雜度：O(logn)（遞迴堆疊，樹高；不含輸出的樹）
 * 解法思路：
 *   1. BST 的中序走訪結果就是由小到大的排序，也就是串列由頭到尾的順序
 *   2. 先走訪一遍串列算出長度 size，用索引區間 [l, r] 表示「這棵子樹要用到串列中第 l 到第 r 個節點」
 *   3. 遞迴順序必須是「左 → 根 → 右」：先建左子樹 [l, mid - 1]，此時串列的成員指標 head 會前進到屬於 mid 的節點
 *   4. 左子樹建完後，head 指向的節點正好是 mid，用它的值建根節點，再把 head 往後移一格
 *   5. 再建右子樹 [mid + 1, r]，串列整個只走一遍，不需要每層重新找中點
 *   6. 區間為空（l > r）時回傳空指標，作為遞迴終止條件
 */

class Solution {
public:
    ListNode* head;   // 成員指標：永遠指向「下一個要拿來建節點」的串列節點，隨中序走訪前進

    // 算出串列長度
    int getLength(ListNode* head) {
        int len = 0;
        ListNode* cur = head;
        while(cur) {
            len++;
            cur = cur->next;
        }
        return len;
    }

    // 用串列中第 l 到第 r 個節點，建出一棵平衡的 BST
    TreeNode* convertListToBST(int l, int r) {
        // 區間為空：沒有節點可用
        if (l > r) {
            return NULL;
        }
        int mid = (l + r) / 2;   // 偶數個時取前面的中間點
        // 中序走訪第一步：先遞迴建左半邊，建完後 head 剛好指向 mid 對應的節點
        TreeNode* left = this->convertListToBST(l, mid - 1);
        // 處理目前節點：用 head 的值當根，接上剛建好的左子樹
        TreeNode* node = new TreeNode(this->head->val);
        node->left = left;
        // 這個串列節點已用掉，指標往後移，供右半邊使用
        this->head = this->head->next;
        // 中序走訪最後一步：遞迴建右半邊
        node->right = this->convertListToBST(mid + 1, r);
        return node;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int size = getLength(head);
        this->head = head;   // 設定成員指標，從串列第一個節點開始消耗
        // 用索引 0 到 size - 1 建樹
        return convertListToBST(0, size - 1);
    }
};