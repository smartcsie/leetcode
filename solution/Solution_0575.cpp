/**
 * 題目：575. Distribute Candies
 * 難度：Easy
 * 描述：Alice 有 n 顆糖（n 為偶數），candyType[i] 是第 i 顆糖的種類。
 *       醫生要求她最多只能吃 n / 2 顆，她想吃到盡可能多的「不同種類」，
 *       回傳她最多能吃到幾種不同的糖。
 *
 * 分類主題：hash-table-uniqueness
 * 技巧：bitset 標記出現過的種類, 負數值域平移成非負索引, 答案取 min(種類數, n / 2)
 *
 * 時間複雜度：O(N + V)，V = 200001 為值域大小（bitset 的 count 需掃過所有位元，實際以字組為單位）
 * 空間複雜度：O(V)，約 25 KB，固定大小
 *
 * 解法思路：不同種類數 vs 可吃數量，取較小者
 * 1. 能吃的上限是 n / 2 顆，所以答案不會超過 n / 2。
 * 2. 糖的總種類數也是上限：就算還有名額，也吃不到不存在的種類。
 * 3. 兩個上限都能達到（挑不同種類各吃一顆即可），所以答案為
 *    min(不同種類數, n / 2)。
 * 4. 統計不同種類數：candyType[i] 的值域是 [-10^5, 10^5]，有負數，
 *    不能直接當索引，先加上 100000 平移到 [0, 200000]，
 *    再用 bitset 的對應位元標記「這個種類出現過」。
 * 5. bitset::count() 回傳被設為 1 的位元數，就是不同種類數。
 */
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        bitset<200001> counts;  // 預設全為 0；第 k 位元為 1 代表（k - 100000）這種糖出現過

        // 值域含負數，加上 100000 平移成非負索引後標記
        for (const int& x : candyType) counts.set(x + 100000);

        int half = candyType.size() / 2;  // 最多能吃的顆數

        // 答案不能超過種類數，也不能超過可吃的顆數
        return min(static_cast<int>(counts.count()), half);
    }
};
