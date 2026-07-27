/**
 * 題目：173. Binary Search Tree Iterator (二元搜尋樹迭代器)
 * 難度：中等 (Medium)
 * 描述：實現一個迭代器，按從小到大的順序遍歷 BST。
 * * 時間複雜度：O(1) 平均值。
 * 空間複雜度：O(h)，h 為樹的高度。
 * * 優化思路：
 * 1. 惰性遍歷：不需要預先儲存所有節點，僅需維護目前的節點路徑。
 * 2. 空間優化：將空間開銷從 O(N) 降至 O(h)。
 */

#include <stack>

class BSTIterator {
private:
    std::stack<TreeNode*> st;

    // 將 node 及 node 左子樹的所有節點推入堆疊
    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    // 返回下一個元素
    int next() {
        TreeNode* topNode = st.top();
        st.pop();
        // 如果該節點有右子樹，則將其右子樹及右子樹的左路徑推入
        pushLeft(topNode->right);
        return topNode->val;
    }
    
    // 檢查是否還有下一個元素
    bool hasNext() {
        return !st.empty();
    }
};
