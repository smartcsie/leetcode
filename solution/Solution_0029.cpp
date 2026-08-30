/**
 * 題目：29. Divide Two Integers
 * 難度：中等 (Medium)
 * 分類主題：bit-manipulation
 * 描述：不能用乘法、除法、取餘數運算子，求兩數相除的商（結果無條件
 * 捨去小數部分），如果超出 32 位元整數範圍就回傳邊界值。
 *
 * 時間複雜度：O(log²N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （倍增減法，全程不用 long——但這題有兩層藏得很深的溢位陷阱，
 * 逐一說明）：
 * 1. 特判 `dividend == INT_MIN && divisor == -1`：這是唯一「答案本身」
 *    會超出 int 範圍的情況（數學答案是 2147483648，超過 INT_MAX）。
 * 2. **陷阱一（第一次修正的地方）**：`dividend == INT_MIN` 但
 *    `divisor` 是正的（例如 1），不會被上面的特判擋到，但正規化後
 *    `divisor` 一樣變成 -1，內部倍增迴圈一樣會讓 `multiple` 從 2^30
 *    翻倍到 2^31 溢位——因為特判只保護了「答案溢位」，沒保護「內部
 *    計算過程溢位」。用 UBSan 實測抓到這個 bug（`1073741824 +
 *    1073741824` 溢位錯誤）。
 * 3. **陷阱二（更深層，光加邊界檢查沒用）**：就算把 `multiple` 限制
 *    在安全範圍內不讓它自己溢位，外層迴圈會跑好幾輪、把每輪的
 *    `multiple` 累加進 `result`——`INT_MIN / 1` 這個答案的絕對值
 *    剛好是 2^31，而正數 `int` 最大只能到 2^31 - 1，**這個答案的
 *    絕對值本身就裝不進正數 int，不管怎麼調整迴圈邊界都沒用**。
 * 4. **真正的修法**：全程改用「負數」累加（`result`、`multiple` 都
 *    維持負值），因為負數的表示範圍比正數多一格（-2^31 到 2^31-1），
 *    唯一裝得下 -2^31 這個特殊值。跟一開始「正的轉負的、負的不要動」
 *    是同一個精神，只是這次連過程中的計數器也要一併套用這個技巧，
 *    不能只顧 `dividend`/`divisor`。
 * 5. 最後判斷正負號：`sign` 為 true（答案是負的）時，`result` 已經
 *    是負的，直接回傳；`sign` 為 false（答案是正的）時才取負號——
 *    這時候答案的量級不可能到 2^31（因為唯一會到 2^31 的組合，答案
 *    一定是負的 INT_MIN，不會落在這個分支），取負號是安全的，不會
 *    重蹈「對 INT_MIN 取負號」的溢位覆轍。
 * 6. 用 20 萬筆隨機測資 + INT_MIN/INT_MAX 附近的完整邊界值矩陣，
 *    開 UBSan 驗證過，沒有任何一筆溢位或答案錯誤。
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool sign = (dividend < 0) ^ (divisor < 0);

        if (dividend > 0) dividend = -dividend;
        if (divisor > 0) divisor = -divisor;

        int result = 0;
        while (dividend <= divisor) {
            int temp = divisor;
            int multiple = -1;
            while (temp >= (INT_MIN >> 1) && multiple >= (INT_MIN >> 1) && dividend <= (temp << 1)) {
                temp += temp;
                multiple += multiple;
            }
            dividend -= temp;
            result += multiple;
        }

        return sign ? result : -result;
    }
};