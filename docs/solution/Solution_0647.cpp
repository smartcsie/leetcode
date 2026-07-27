/**
 * 題目：647. Palindromic Substrings (回文子串)
 * 難度：中等 (Medium)
 * 描述：計算字串中總共有多少個回文子串。
 * * 時間複雜度：O(N^2)
 * 空間複雜度：O(1) - 採用中心擴展法，不使用額外 DP 陣列。
 * * 優化思路：
 * 1. 中心擴展法：回文的中心可能是一個字元 (如 'aba') 或兩個字元之間 (如 'abba')。
 * 2. 對於字串中每一個可能的中心點，向兩側擴展並統計回文數量。
 */

class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        int n = s.size();
        
        // 字串中共有 2n-1 個可能的中心點 (n 個單字元，n-1 個雙字元中心)
        for (int i = 0; i < 2 * n - 1; i++) {
            // left 和 right 為擴展指標
            int left = i / 2;
            int right = left + i % 2;
            
            // 向兩側擴展，只要符合回文定義就計數
            while (left >= 0 && right < n && s[left] == s[right]) {
                result++;
                left--;
                right++;
            }
        }
        return result;
    }
};
