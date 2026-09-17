/**
 * 題目：Compute Decimal Representation
 * 難度：簡單 (Easy)
 * 描述：將整數拆解為十進位下的位值加總陣列 (例如 504 -> [500, 4])。
 * 優化重點：
 * 1. 防禦性編程：在迴圈末端檢查 n > 0，避免最後一輪 base 溢位。
 * 2. 空間效率：僅儲存非零位值，符合題目常見需求。
 *
 * 時間複雜度：O(logN)
 * 空間複雜度：O(logN)
 */

class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        int multipler = 1;
        while(n > 0) {
            int d = n % 10;
            if(d > 0) ans.push_back( d * multipler);
            if(n >= 10) multipler *= 10;
            n /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
