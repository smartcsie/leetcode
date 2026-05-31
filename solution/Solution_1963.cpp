/**
 * 題目：1963. Minimum Number of Swaps to Make the String Balanced (使字串平衡的最小交換次數)
 * 難度：中等 (Medium)
 * 描述：給定一個包含 '[' 和 ']' 的字串，計算使其平衡所需的最小交換次數。
 * * 時間複雜度：O(N) - 遍歷一次字串。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 優化思路：
 * 我們只需要追蹤「無法被右括號抵銷的左括號」剩餘數量。
 * 每次交換可以修正兩個不匹配的括號對，因此結果是 (unbalanced_pairs + 1) / 2。
 */

class Solution {
public:
    int minSwaps(string s) {
        int balance = 0; // 代表當前未配對的左括號數量
        
        for (char ch : s) {
            if (ch == '[') {
                balance++;
            } else {
                // 如果有左括號可供配對，則消耗一個
                if (balance > 0) {
                    balance--;
                }
            }
        }
        
        // 剩餘的 balance 是無法配對的左括號數量
        // 一次交換可以修正兩個不匹配的對，例如 "[[]]" -> "[] []"
        return (balance + 1) / 2;
    }
};
