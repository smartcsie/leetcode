/**
 * 題目：233. Number of Digit One
 * 難度：困難 (Hard)
 * 描述：給定一個整數 n，計算 1 到 n 之間所有整數裡，數字 '1' 總共出現
 * 幾次（例如 13 裡的 1 跟 3，13 出現了「1」這個數字一次；11 則出現
 * 兩次）。
 *
 * 時間複雜度：O(log N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （逐位分析法，不是傳統的「狀態轉移表」DP，而是對每一個「位數」
 * 分別公式計算貢獻，這是 Digit DP 題目常見的另一種變形）：
 * 1. 固定看「某一位」（例如十位、百位）上出現 1 的總次數，把 1~n
 *    拆成三段：這一位左邊的數字（high）、這一位本身（cur）、這一位
 *    右邊的數字（low），i 是目前這一位的位值（1, 10, 100...）。
 * 2. 這一位上出現 1 的次數規律：
 *    - 如果這一位的數字 cur > 1：這一位能貢獻 (high + 1) * i 次 1
 *      （因為 high 每增加 1，這一位都能完整跑過 0~9，包含一次是 1；
 *      加上 high 本身這一輪也能跑滿）。
 *    - 如果 cur == 1：這一位貢獻 high * i + (low + 1) 次（high 部分
 *      跟上面一樣，但這一輪只能跑到 low，不能跑滿到 9）。
 *    - 如果 cur == 0：這一位貢獻 high * i 次（這一輪完全不會經過
 *      這一位是 1 的情況）。
 * 3. 程式碼用一個統一公式涵蓋這三種情況，不用寫 if/else 分支：
 *    count += (n / divider) * i + min(max(n % divider - i + 1, 0), i)
 *    其中 divider = i * 10。這個式子巧妙地把 cur/low 的判斷「壓縮」進
 *    一個 min/max 表達式裡。
 * 4. 對每個位數（i = 1, 10, 100, ...）重複這個計算並累加，直到 i > n
 *    為止，總和就是答案。
 */
class Solution {
public:
    int countDigitOne(int n) {
        long long count = 0;
        for (long long i = 1; i <= n; i *= 10) {
            long long divider = i * 10;
            count += (n / divider) * i + min(max((long long)(n % divider) - i + 1, 0LL), i);
        }
        return (int)count;
    }
};
