/**
 * 題目：914. X of a Kind in a Deck of Cards (卡牌分組)
 * 難度：簡單 (Easy)
 * 描述：給定一副牌 deck，每張牌上都有一個整數。判斷是否存在一個大於等於 2 的整數 X，
 *       使得可以把整副牌分成若干組，每組恰好有 X 張牌，且同一組內的牌數字都相同。
 *
 * 時間複雜度：O(N) - 統計次數需要 O(N)，計算 GCD 的次數最多為不同數字的種類數，遠小於 N。
 * 空間複雜度：O(N) - 雜湊表 count 最壞情況下需要儲存 N 個不同的數字及其次數。
 *
 * 解法思路：
 * 1. 統計每種數字出現的次數 (Frequency Counting)：
 *    - 用 unordered_map<int, int> count 記錄 deck 中每個數字各自出現的次數。
 * 2. 求所有次數的最大公因數 (GCD of All Frequencies)：
 *    - 依序對每種數字的出現次數計算 GCD，gcdVal 初始為 0（因為 gcd(0, value) = value，
 *      能正確初始化第一次疊代的結果）。
 * 3. 判斷是否存在合法的分組大小 X：
 *    - 若所有次數的 GCD（gcdVal）大於等於 2，代表可以選擇 X = gcdVal（或其任何因數，
 *      只要 >= 2），讓每種數字的張數都恰好能被 X 整除，滿足分組要求。
 * 4. 回傳判斷結果：
 *    - 直接回傳 gcdVal >= 2 作為最終答案。
 */
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> count;
        int gcdVal = 0;
        for (const int d : deck)
            ++count[d];

        for (const auto& [_, value] : count)
            gcdVal = gcd(gcdVal, value);

        return gcdVal >= 2;
    }
};
