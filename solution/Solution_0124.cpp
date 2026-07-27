/**
 * 題目：124. Binary Tree Maximum Path Sum (二元樹中的最大路徑和)
 * 難度：困難 (Hard)
 * 描述：找出二元樹中任意兩點間的最大路徑和（路徑可經過節點，不可分叉）。
 * * 時間複雜度：O(N) - 每個節點僅遍歷一次。
 * 空間複雜度：O(H) - H 為樹的高度，遞迴深度。
 * * 設計思路：
 * 1. 遞迴函式回傳的是「以當前節點為頂點，向左或向右延伸的最大路徑和」。
 * 2. 如果子樹路徑和小於 0，則該路徑對最大值無貢獻，故取 `max(childSum, 0)`。
 * 3. 每一層更新最大值為：`root->val + leftGain + rightGain`。
 */

class Solution {
private:
    // 遞迴計算節點路徑和
    int calculateGain(TreeNode* node, int& max_sum) {
        if (!node) return 0;
        
        // 如果子樹貢獻為負，則捨棄該子樹 (取 0)
        int left_gain = max(calculateGain(node->left, max_sum), 0);
        int right_gain = max(calculateGain(node->right, max_sum), 0);
        
        // 當前節點作為路徑轉折點時的路徑和
        int current_path_sum = node->val + left_gain + right_gain;
        
        // 更新全域最大值
        max_sum = max(max_sum, current_path_sum);
        
        // 回傳對父節點的貢獻（只能選擇左或右路徑的一側）
        return node->val + max(left_gain, right_gain);
    }

public:
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN; // 必須初始化為極小值，因節點值可能為負
        calculateGain(root, max_sum);
        return max_sum;
    }
};
