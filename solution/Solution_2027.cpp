/**
 * 題目：2027. Minimum Moves to Convert String
 * 難度：Easy
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 * 分類主題：greedy
 *
 * 解法說明：
 * 每次操作可以選連續 3 個字元，全部變成 'O'。
 * 貪心策略：從左到右掃描，遇到第一個 'X' 就以它為起點做一次操作，
 * 一次覆蓋 3 個字元（包含它自己和後面兩個），然後直接跳過這 3 格。
 * 讓每次操作盡量往右覆蓋，才能用最少次數處理完所有 'X'。
 */

class Solution {
public:
    int minimumMoves(string s) {
        int count = 0;
        for(int i = 0; i < s.size();) {
            if(s[i] == 'O') {
                i++; 
            } else {
                i += 3;
                count++;
            }
        }
        return count;
    }
};
