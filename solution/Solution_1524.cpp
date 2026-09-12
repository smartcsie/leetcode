/**
 * 題目：1524. Number of Sub-arrays With Odd Sum
 * 難度：中等 (Medium)
 * 分類主題：array-prefix-sum
 * 描述：給定一個整數陣列 arr，求有幾個子陣列的總和是奇數，答案對
 * 10^9+7 取模。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （前綴和 + 奇偶性計數，核心公式：子陣列 [l+1, r] 的總和
 * = prefix[r] - prefix[l]，這個差要是奇數，prefix[r] 跟 prefix[l]
 * 的奇偶性必須不一樣）：
 * 1. `countEven`、`countOdd` 分別統計「目前為止，前綴和是偶數/奇數
 *    的次數」。初始化 `countEven = 1`：這代表「還沒加任何元素」時的
 *    前綴和是 0（偶數），這個空前綴要算進統計裡，才能正確配對到
 *    「從陣列開頭算起」的子陣列。
 * 2. 掃描每個元素，累加進 `prefix`（這裡直接累加原始數值，不用先
 *    對 2 取餘數——因為只在乎奇偶性，`prefix & 1` 這個位元運算可以
 *    直接從完整的累加和判斷奇偶，效果跟「每次都對 2 取餘數再累加」
 *    完全一樣，寫法更直覺）。
 * 3. **配對邏輯**：如果目前的 `prefix` 是奇數，要找「之前奇偶性是
 *    偶數」的位置配對（兩者相減才會是奇數），所以 `ans += countEven`；
 *    是偶數的話則反過來 `ans += countOdd`。
 * 4. 配對完成後，把目前這個前綴的奇偶性也計入對應的計數器
 *    （`countOdd++` 或 `countEven++`），留給後面的位置繼續查詢配對。
 * 5. `ans` 用 `long long` 是為了避免中途累加的過程中超出 `int`
 *    範圍（雖然最終取模後會落在合法範圍，但取模前的中間值可能較
 *    大），最後回傳前才取一次模。
 * 6. 這是這題唯一正確、也是標準的 O(N) 解法：跟直接累加原始值再
 *    取奇偶性 vs 每次對 2 取餘數再累加，兩種寫法在數學上完全等價，
 *    純粹是風格選擇。
 */
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        constexpr int MOD = 1e9 + 7;
        int countEven = 1, countOdd = 0;
        int prefix = 0;
        long long ans = 0;
        for (int num : arr) {
            prefix += num;
            if (prefix & 1) {
                ans += countEven;
                countOdd++;
            } else {
                ans += countOdd;
                countEven++;
            }
        }
        return ans % MOD;
    }
};
