/**
 * 題目：821. Shortest Distance to a Character
 * 難度：簡單 (Easy)
 * 描述：計算字串中每個字元距離目標字元 'c' 的最短距離。
 * * 優化重點：
 * 1. 兩次掃描 (Two-pass)：先從左到右紀錄最近的目標字元距離，再從右到左更新最小值。
 * 2. 邊界處理：使用一個足夠大的無限大值 (inf) 處理字串邊緣沒有目標字元的情況。
 */

class Solution {
public:
    std::vector<int> shortestToChar(std::string s, char c) {
        int n = s.size();
        // 使用足夠大的數代表無窮遠
        const int inf = 1e5; 
        std::vector<int> res(n, inf);

        // 第一次掃描：從左往右 (計算左側最近的 c)
        int pre = -inf;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) pre = i;
            res[i] = std::min(res[i], i - pre);
        }

        // 第二次掃描：從右往左 (計算右側最近的 c)
        int next = inf;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) next = i;
            res[i] = std::min(res[i], next - i);
        }

        return res;
    }
};
