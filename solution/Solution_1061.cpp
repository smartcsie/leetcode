/**
 * 題目：1061. Lexicographically Smallest Equivalent String
 * 難度：中等 (Medium)
 * 分類主題：greedy-string-construction
 * 描述：給定等長的字串 s1、s2，s1[i] 和 s2[i] 視為「等價字母」（等價
 * 關係可以傳遞）。給定另一個字串 baseStr，把每個字母換成它所在等價
 * 群組裡字典序最小的字母，求轉換後的字串。
 *
 * 時間複雜度：O(N + M * α(26))，N 是 s1/s2 長度、M 是 baseStr 長度
 * 空間複雜度：O(26)
 *
 * 解法思路：
 * （Union-Find + 貪心：每個等價群組的「代表」永遠是群組裡字典序最小
 * 的字母，這是這題能用 Union-Find 解決字串問題的關鍵設計）：
 * 1. 用 26 個字母各自的並查集，parent[i] 初始化為自己。
 * 2. 對每一對 (s1[i], s2[i])，做 union 合併操作。**關鍵設計**：合併
 *    時永遠讓「字母較小」的那個字元當作根節點（代表），而不是隨便
 *    指定或用 rank/size 優化——這樣任何時候查詢某個字母的根節點，
 *    得到的就直接是「這個等價群組裡字典序最小的字母」，不需要額外
 *    一輪遍歷去找每個群組的最小值。
 * 3. 建立好所有等價關係後，對 baseStr 裡的每個字元，查詢它的根節點
 *    （find 操作，帶路徑壓縮），根節點就是它應該被替換成的字母。
 * 4. 依序替換每個字元，組成最終答案字串。
 */
class Solution {
    vector<int> parent;
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (px < py) parent[py] = px;
        else parent[px] = py;
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        iota(parent.begin(), parent.end(), 0);

        for (int i = 0; i < (int)s1.size(); ++i) {
            unite(s1[i] - 'a', s2[i] - 'a');
        }

        string result;
        for (char c : baseStr) {
            result += (char)('a' + find(c - 'a'));
        }
        return result;
    }
};
