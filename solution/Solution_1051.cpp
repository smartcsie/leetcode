/**
 * 題目：1051. Height Checker (高度檢查器)
 * 難度：簡單 (Easy)
 * 描述：統計與非遞減排序後陣列不相符的索引數量。
 * * 時間複雜度：O(N) - 遍歷數次陣列，無須完整排序。
 * 空間複雜度：O(K) - K 為高度範圍 (通常為 100)，即 O(1) 空間。
 * * 優化思路 (Counting Sort)：
 * 由於身高範圍有限 (1-100)，我們不需進行 O(N log N) 的排序。
 * 建立一個頻率陣列紀錄每個高度出現次數，再依序比對即可。
 */

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // 使用計數陣列 (假設高度範圍在 1-100 之間)
        int count[101] = {0};
        for (int h : heights) {
            count[h]++;
        }
        
        int res = 0;
        int current_height = 1;
        for (int i = 0; i < heights.size(); i++) {
            // 找出下一個非零的計數位置，即為排序後的正確高度
            while (count[current_height] == 0) {
                current_height++;
            }
            
            // 若原陣列高度與排序後不符，計數器 +1
            if (heights[i] != current_height) {
                res++;
            }
            
            // 使用完該高度，數量遞減
            count[current_height]--;
        }
        
        return res;
    }
};
