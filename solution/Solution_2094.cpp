/**
 * 題目：2094. Finding 3-Digit Even Numbers (找出 3 位偶數)
 * 難度：簡單 (Easy)
 * 描述：由輸入的數字陣列 digits 組成所有可能的 3 位偶數，結果需升序回傳。
 * * 時間複雜度：O(N)，N 為 digits 長度。
 * 空間複雜度：O(1)，頻率陣列固定為 10。
 * * 優化思路：
 * 1. 資源回溯法：在迴圈中動態扣除並恢復 count，讓判斷邏輯更為簡潔。
 * 2. 順序性：由於迴圈是從小到大遍歷 (hun: 1-9, ten: 0-9, unit: 0-8)，
 * 產生的 res 自動就是排序過的。
 */

#include <vector>

class Solution {
public:
    std::vector<int> findEvenNumbers(std::vector<int>& digits) {
        int counts[10] = {0};
        for (int d : digits) counts[d]++;
        
        std::vector<int> res;
        
        // 遍歷所有可能的 3 位偶數 (100-998)
        for (int hun = 1; hun <= 9; ++hun) {
            if (counts[hun]-- > 0) { // 借出百位
                for (int ten = 0; ten <= 9; ++ten) {
                    if (counts[ten]-- > 0) { // 借出十位
                        for (int unit = 0; unit <= 8; unit += 2) {
                            if (counts[unit]-- > 0) { // 借出個位
                                res.push_back(hun * 100 + ten * 10 + unit);
                            }
                            counts[unit]++; // 歸還個位
                        }
                        counts[ten]++; // 歸還十位
                    }
                }
                counts[hun]++; // 歸還百位
            }
        }
        
        return res;
    }
};
