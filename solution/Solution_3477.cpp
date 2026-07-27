/**
 * 題目：3477. Fruits Into Baskets II
 * 描述：給你兩個陣列 fruits 和 baskets，長度皆為 n。
 *       對於每一個水果 fruits[i]，請在籃子中尋找第一個容量大於或等於該水果大小的可用籃子（baskets[j] >= fruits[i]）。
 *       一旦放入，該水果和籃子即被消耗（標記為不可用）。返回無法成功放置的水果數量。
 * 
 * 解法思路（雙迴圈暴力模擬法）：
 * 1. 依照題目規則模擬：
 *    - 依序遍歷每一個水果，再從頭掃描每一個籃子，尋找第一個滿足條件（`fruits[i] <= baskets[j]`）的籃子。
 * 2. 狀態更新：
 *    - 找到後將該水果和籃子賦值為 0（代表已使用），將未放置水果數減 1，並跳出內層迴圈。
 * 3. 適用場景：
 *    - 當資料規模 $N$ 較小時（如 $N \le 1000$），這種 $O(N^2)$ 的暴力模擬法直覺、簡潔且完全不會超時。
 * 時間複雜度：O(N^2) - 雙層迴圈暴力枚舉每個水果種類的最長區段。
 * 空間複雜度：O(1) - 僅使用常數空間。

 */

class Solution {
public:
    int numOfUnplacedFruits(std::vector<int>& fruits, std::vector<int>& baskets) {
        int n = fruits.size();
        int ans = n; // 初始假設所有水果皆無法放置
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 如果當前籃子的容量大於或等於水果大小
                if (fruits[i] <= baskets[j]) {
                    fruits[i] = 0;   // 標記該水果已被放置
                    baskets[j] = 0;  // 標記該籃子已被使用
                    ans--;           // 成功放置的水果數加一，未放置數減一
                    break;           // 尋找下一個水果
                }
            }
        }
        
        return ans;
    }
};
