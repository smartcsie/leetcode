// 題目：404. Sum of Left Leaves
// 難度：Easy
// 時間複雜度：O(n)（每條邊最多走兩次）
// 空間複雜度：O(1)（不用遞迴堆疊或佇列）
// 分類主題：tree / binary-tree
// 技巧：Morris Traversal（線索二元樹）：暫時把中序前驅的 right 指回目前節點當作「回頭的路」，走完再拆掉

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int totalSum = 0;
        TreeNode* currentNode = root;
        while(currentNode != nullptr) {
            // 沒有左子樹：不需要回頭，直接往右走
            if(currentNode->left == nullptr) {
                currentNode = currentNode->right;
            } else {
                // previous 先指向左子節點，之後會往右走到左子樹最右邊的節點
                TreeNode* previous = currentNode->left;

                // 左子節點是葉子就計入答案
                // 只會在第一次走到 currentNode 時計入：
                // 第二次回來時，這個葉子的 right 已被接成線索（指向 currentNode），
                // 不再是 nullptr，所以不會被誤判成葉子而重複計算
                if(previous->left == nullptr && previous->right == nullptr) {
                    totalSum += previous->val;
                }

                // 找 currentNode 的中序前驅：左子樹中最右邊的節點
                // 停止條件：right 是空的（第一次），或 right 已經指回 currentNode（第二次）
                while(previous->right != nullptr && previous->right != currentNode) {
                    previous = previous->right;
                }

                if(previous->right == nullptr) {
                    // 第一次到達：先接線索（前驅的 right 指回 currentNode），
                    // 這樣走完左子樹後才有路可以回來
                    previous->right = currentNode;
                    currentNode = currentNode->left;
                } else {
                    // 第二次到達：左子樹已經走完，拆掉線索還原樹的結構，改走右子樹
                    previous->right = nullptr;
                    currentNode = currentNode->right;
                }
            }
        }
        return totalSum;
    }
};