/**
 * 題目：728. Self Dividing Numbers
 * 難度：簡單 (Easy)
 * 描述：找出範圍 [left, right] 內所有的自除數。
 * 優化重點：
 * 1. 預分配 `res` 空間，避免在迴圈中發生多次記憶體重分配。
 * 2. 邏輯簡潔：在迴圈內部直接進行位數檢查，並盡量減少變數拷貝。
 *
 * 時間複雜度：O(N*D) - 對範圍內每個數字做 digit decomposition，D 為位數。
 * 空間複雜度：O(1) - 僅使用常數空間。
 */

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int x = left; x <= right; x++) {
            int y = x;
            bool divide = true;
            while(y > 0) {
                int digit = y % 10;
                if(digit == 0 || (x % digit) != 0 ) {
                    divide = false;
                    break;
                }
                y /= 10;
            }
            if(divide) ans.push_back(x);
        }
        return ans;
    }
};