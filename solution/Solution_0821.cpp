/**
 * 題目：821. Shortest Distance to a Character
 * 難度：簡單 (Easy)
 * 描述：計算字串中每個字元距離目標字元 'c' 的最短距離。
 * 優化重點：
 * 1. 兩次掃描 (Two-pass)：先從左到右紀錄最近的目標字元距離，再從右到左更新最小值。
 * 2. 邊界處理：使用一個足夠大的無限大值 (inf) 處理字串邊緣沒有目標字元的情況。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans(n, INT_MAX);
        for(int i = 0, pre = INT_MIN ; i < n; i++) {
            if(s[i] == c) pre = i;
            if(pre != INT_MIN) ans[i] = min(ans[i], i - pre);
        }
        for(int i = n - 1, next = INT_MAX ; i >= 0; i--) {
            if(s[i] == c) next = i;
            if(next != INT_MAX) ans[i] = min(ans[i], next - i);
        }
        return ans;
    }
};