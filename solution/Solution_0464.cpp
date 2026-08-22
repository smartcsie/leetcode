/**
 * 題目：464. Can I Win
 * 難度：中等 (Medium)
 * 描述：兩個玩家輪流從 1 到 maxChoosableInteger 之間選一個「還沒被選
 * 過」的數字，累加到總分裡，誰先讓總分達到或超過 desiredTotal 誰就
 * 獲勝。兩人都用最佳策略遊玩，求先手玩家是否保證能贏。
 *
 * 時間複雜度：O(2^N * N)，N = maxChoosableInteger
 * 空間複雜度：O(2^N)
 *
 * 解法思路：
 * （Bitmask DP，狀態是「哪些數字已經被選過」，用一個整數的每一位
 * 代表一個數字選過與否）：
 * 1. 先處理兩個特殊情況：desiredTotal <= 0 代表不用選就贏了，直接
 *    true；如果所有數字加起來都不夠 desiredTotal（fullSum 
 *    desiredTotal），代表怎麼選都湊不到，直接 false。
 * 2. usedMask 是一個 bitmask，第 i-1 個 bit 代表數字 i 有沒有被選過
 *    （數字範圍最多到 20，所以用一個 int 的 bit 就夠存）。
 * 3. dp(usedMask, remaining) 代表「目前已選過 usedMask 這些數字，
 *    還需要湊到 remaining 分」時，輪到的這位玩家是否能保證獲勝。
 * 4. 狀態轉移：枚舉每個還沒被選過的數字 i：
 *    - 如果選了 i 之後 i >= remaining（直接達標獲勝），或是選了 i
 *      之後輪到對手時對手會輸（!dp(新狀態, remaining - i) 為 true），
 *      代表「我」選這個數字就能贏，直接回傳 true。
 *    - 如果窮舉完所有還沒選過的數字，都沒有辦法讓「我」贏，回傳 false。
 * 5. 用 unordered_map<int, bool> 做記憶化：因為 remaining 可以由
 *    usedMask 反推出來（desiredTotal 減去 usedMask 裡所有數字的總和），
 *    所以只需要用 usedMask 當 key 就能唯一決定狀態，不用把 remaining
 *    也塞進 key 裡，省空間。
 * 6. 答案是 dp(0, desiredTotal)（一開始沒有數字被選過）。
 */
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0) return true;
        int fullSum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (fullSum < desiredTotal) return false;

        unordered_map<int, bool> memo;
        function<bool(int,int)> dp = [&](int usedMask, int remaining) -> bool {
            if (memo.count(usedMask)) return memo[usedMask];
            for (int i = 1; i <= maxChoosableInteger; ++i) {
                int bit = 1 << (i - 1);
                if (usedMask & bit) continue;
                if (i >= remaining || !dp(usedMask | bit, remaining - i)) {
                    return memo[usedMask] = true;
                }
            }
            return memo[usedMask] = false;
        };
        return dp(0, desiredTotal);
    }
};
