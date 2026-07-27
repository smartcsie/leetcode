/**
 * 題目：1089. Duplicate Zeros (複寫零)
 * 難度：簡單 (Easy)
 * 描述：在 O(1) 額外空間下，將所有 0 複寫一次，同時保持陣列長度不變。
 * * 時間複雜度：O(N) - 兩次線性掃描。
 * 空間複雜度：O(1) - 原地修改。
 * * 優化思路：
 * 1. 先計算出陣列中「真正能填入」原陣列的最後一個元素位置。
 * 2. 從後往前進行覆寫，避免從前往後填寫時，後面的數據被過早覆蓋。
 */

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeros = 0;
        int i = 0;

        // 1. 找出最終會停在陣列中的最後一個元素索引 i
        // 並統計有多少個零需要被複製
        for (i = 0; i < n - zeros; ++i) {
            if (arr[i] == 0) {
                // 特殊情況：如果剛好遇到最後一個零且無法完整複製
                if (i == n - zeros - 1) {
                    arr[n - 1] = 0;
                    n--; // 縮小處理範圍
                    break;
                }
                zeros++;
            }
        }

        // 2. 從後往前原地覆寫
        // i 指向最後一個要處理的元素，j 指向陣列末端
        for (int j = arr.size() - 1; i >= 0; --i, --j) {
            if (arr[i] == 0) {
                arr[j--] = 0; // 寫入兩個 0
                arr[j] = 0;
            } else {
                arr[j] = arr[i]; // 複製元素
            }
        }
    }
};
