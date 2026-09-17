/**
 * 題目：3120. Count the Number of Special Characters I
 * 難度：簡單 (Easy)
 * 分類主題：bit-manipulation-mask
 * 描述：給定一個字串 word，如果某個字母同時以大寫跟小寫出現在字串裡，
 * 就稱它是「特殊字母」，求總共有幾個特殊字母。
 *
 * 時間複雜度：O(N)，N 是字串長度
 * 空間複雜度：O(1)（bitset 固定只需要 26 個 bit）
 *
 * 解法思路：
 * （Bitmask，用 bitset 取代之前的 accumulate 版本，是更直觀的寫法：
 * 直接用 STL 的 `&`（AND）跟 `.count()`，不用自己手動比較兩個遮罩）：
 * 1. 用兩個 `bitset<26>`（`upper`、`lower`）分別記錄「出現過的大寫
 *    字母」跟「出現過的小寫字母」，各自 26 個 bit 對應 a~z。
 * 2. 掃描字串每個字元：是大寫就設定 `upper` 對應的 bit
 *    （`c - 'A'`），是小寫就設定 `lower` 對應的 bit（`c - 'a'`）。
 *    跟之前的 accumulate 版本邏輯完全一樣，只是這裡用 `bitset` 的
 *    `.set()` 取代手動的 `|=` 位元運算，語意更清楚。
 * 3. **核心技巧**：`upper & lower` 直接對兩個 bitset 做 AND 運算，
 *    結果裡「兩邊都出現過」的字母，對應的 bit 才會是 1——這跟之前
 *    版本的 `ans[0] & ans[1]` 是同一個概念，只是 `bitset` 提供了
 *    現成的 `&` 運算子跟 `.count()` 成員函式，不用像 accumulate 版
 *    那樣還要另外呼叫 `__builtin_popcount`。
 * 4. `.count()` 直接回傳這個 bitset 裡有幾個 bit 是 1，就是答案。
 * 5. **跟 accumulate 版本的比較**：兩者本質上是同一個演算法（雙
 *    bitmask + AND + popcount），差別只在於用 `int` 手動操作位元
 *    運算子，還是用 `bitset` 這個 STL 容器把同樣的操作包裝成更好讀
 *    的成員函式呼叫，效能上幾乎沒有差異，純粹是可讀性風格選擇。
 */
class Solution {
public:
    int numberOfSpecialChars(string word) {
        bitset<26> upper, lower;
        for(const char& c : word) {
            if(isupper(c)) upper.set(c - 'A');
            else lower.set(c - 'a');
        }
        return (upper & lower).count();
    }
};