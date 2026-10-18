/**
 * 題目：1250. Check If It Is a Good Array
 * 難度：困難 (Hard)
 * 描述：給定正整數陣列 nums。若能從中選出某些數字，各自乘上任意整數
 *       （可正可負可為 0）後相加，得到 1，則稱 nums 為「好陣列」。
 *       判斷 nums 是否為好陣列。
 *
 * 分類主題：math-gcd
 * 技巧：貝祖定理 Bézout's identity, 累積 gcd, gcd(x, 0) = x 當初始值
 *
 * 時間複雜度：O(N log M)，M 為 nums 中的最大值（每次 gcd 約 O(log M)）
 * 空間複雜度：O(1)
 *
 * 解法思路：貝祖定理 + 整體 gcd
 * 1. 貝祖定理：對整數 a、b，所有 ax + by（x、y 為任意整數）能湊出的值，
 *    恰好是 gcd(a, b) 的所有倍數。推廣到多個數，結論相同：
 *    nums 所有元素的線性組合能湊出的最小正整數，就是整個陣列的 gcd。
 * 2. 所以能湊出 1，若且唯若整個陣列的 gcd 等於 1（元素互質）。
 * 3. 實作上用 val 累積 gcd：初始為 0，因為 gcd(x, 0) = x，
 *    第一個元素進來後 val 就等於它本身。
 * 4. 走完整個陣列後，val 是全體的 gcd，等於 1 即回傳 true。
 *
 * 備註：不需要真的找出係數，只要判斷 gcd 是否為 1。
 *       gcd 一旦變成 1 就不會再變大，可以提早回傳 true。
 */
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int val = 0;  // 目前累積的 gcd，初始 0 使 gcd(x, 0) = x
        for (const int& x : nums) {
            val = gcd(x, val);  // 把 x 併入整體 gcd
            if(val == 1) return true;
        }
        return val == 1;  // 整體 gcd 為 1，代表能線性組合出 1
    }
};
