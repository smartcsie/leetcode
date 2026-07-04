/**
 * 題目：Compute Decimal Representation
 * 難度：簡單 (Easy)
 * 描述：將整數拆解為十進位下的位值加總陣列 (例如 504 -> [500, 4])。
 * * 優化重點：
 * 1. 防禦性編程：在迴圈末端檢查 n > 0，避免最後一輪 base 溢位。
 * 2. 空間效率：僅儲存非零位值，符合題目常見需求。
 */

class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> res;
        int base = 1;
        while(n > 0) {
            int digit = n % 10;
            if(digit != 0) {
                res.push_back(digit * base);
            }
            n /= 10 ;
            if(n > 0) base *= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
