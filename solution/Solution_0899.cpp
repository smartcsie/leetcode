/**
 * 題目：899. Orderly Queue
 * 難度：困難 (Hard)
 * 分類主題：greedy-string-construction
 * 描述：給定一個字串 s 和一個整數 k，每次操作可以選最前面 k 個字元
 * 裡的任一個，把它移到字串最後面（如果 k=1，只能移動最前面那個）。
 * 可以進行任意次操作，求能得到的字典序最小字串。
 *
 * 時間複雜度：O(N²)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （這題是一個「觀察出隱藏數學性質」的貪心題，關鍵在於 k 是否大於 1
 * 會讓能做到的操作範圍完全不同）：
 * 1. **k > 1 的情況**：只要 k >= 2，就可以利用「前 k 個字元裡任選
 *    一個移到最後」這個操作，模拟出類似冒泡排序的效果——可以把任意
 *    兩個相鄰字元交換順序（透過幾次移動），因此能排出**任意排列**，
 *    直接把字串排序（sort）就是字典序最小的結果。
 * 2. **k = 1 的情況**：這時候唯一能做的操作是「把最前面的字元搬到
 *    最後面」，重複做這個操作，能得到的所有可能結果，剛好就是這個
 *    字串所有的**旋轉（rotation）**。窮舉所有旋轉位置，逐一比較，
 *    取字典序最小的那個。
 * 3. 這題不需要複雜的演算法，難點完全在於想清楚「k>1 時操作能力
 *    等價於任意排列」這個觀察，一旦想通，程式碼非常簡短。
 */
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        }
        string best = s;
        string rotated = s;
        for (int i = 0; i < (int)s.size(); ++i) {
            rotated = rotated.substr(1) + rotated[0];
            best = min(best, rotated);
        }
        return best;
    }
};
