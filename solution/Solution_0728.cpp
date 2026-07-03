/**
 * 題目：728. Self Dividing Numbers
 * 難度：簡單 (Easy)
 * 描述：找出範圍 [left, right] 內所有的自除數。
 * * 優化重點：
 * 1. 預分配 `res` 空間，避免在迴圈中發生多次記憶體重分配。
 * 2. 邏輯簡潔：在迴圈內部直接進行位數檢查，並盡量減少變數拷貝。
 */

class Solution {
private:
    bool selfDividing(int n) {
        int temp = n;
        while(temp > 0) {
            int digit = temp % 10;
            if( digit == 0 || n % digit != 0) return false;
            temp /= 10;
        }
        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        res.reserve(right - left + 1);
        for(int i = left; i<= right; i++) {
            if(selfDividing(i)) {
                res.push_back(i);
            }
        }
        return res;
    }
};
