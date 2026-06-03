/**
 * 題目：96. Unique Binary Search Trees (不同的二元搜尋樹)
 * 難度：中等 (Medium)
 * 描述：給定 n，求出由 1 到 n 組成的二元搜尋樹 (BST) 結構數量。
 * * 時間複雜度：O(N^2) - 雙重迴圈計算。
 * 空間複雜度：O(N) - 儲存 DP 陣列。
 * * 設計思路：
 * 卡塔蘭數公式：G(n) = Σ G(i-1) * G(n-i)，其中 i 為選定的根節點。
 * G(0) = 1, G(1) = 1。
 */

class Solution {
public:
    int numTrees(int n) {
        // 使用 vector 初始化為 0，DP[i] 表示節點數為 i 時的結構數量
        vector<int> G(n + 1, 0);
        G[0] = 1; // 空樹只有一種結構
        G[1] = 1; // 單一節點只有一種結構
        
        // 從節點數 2 開始推導
        for (int i = 2; i <= n; ++i) {
            // 以 j 作為根節點，j 的範圍從 1 到 i
            for (int j = 1; j <= i; ++j) {
                // 左子樹節點數為 j-1，右子樹節點數為 i-j
                G[i] += G[j - 1] * G[i - j];
            }
        }
        
        return G[n];
    }
};
