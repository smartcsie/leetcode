/**
 * 題目：2246. Difference Between Maximum and Minimum Price Sum
 * 難度：困難 (Hard)
 * 描述：給定一棵有 n 個節點的樹（用邊列表表示，不是二元樹），每個節點
 * 有一個價值 price[i]。選一個節點當根，定義「價格和」為根到某個節點
 * 路徑上所有節點價值總和；再選一個節點當「起點」，該路徑的成本 = 
 * 價格和 - 起點的價值（起點可以是路徑上任一節點，為了讓成本最大，
 * 一定會選價值最小的節點當起點扣掉）。對所有可能的根、可能的路徑，
 * 求最大的成本。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （Tree DP，關鍵觀察：因為所有節點價值都是正數，一條路徑裡「價值
 * 最小、拿來扣掉」的節點一定是路徑的其中一個端點，而且一定是「葉子端」
 * 那一端，不會是中間節點——所以問題等價於：找一條路徑，扣掉它其中一個
 * 端點（較小價值的那個）之後，剩下的總和最大）：
 * 1. 用 DFS 對每個節點，維護兩個值：
 *    - maxSum1：從這個節點往下走到某片葉子，完整計入所有節點價值的
 *      最大路徑和（含這個節點自己）。
 *    - maxSum2：從這個節點往下走到某片葉子，但「扣掉最末端那個葉子的
 *      價值」之後的最大路徑和——相當於預先算好「如果這條路徑的葉子端
 *      被選為要扣掉的最小值端點」，剩下多少。
 * 2. 對每個節點，枚舉它的每個子節點，把「目前為止走過的子節點路徑」
 *    跟「這個新子節點」組合：一邊用 maxSum1（完整計價，這一側的葉子
 *    不被扣）、另一邊用 maxSum2（這一側的葉子被扣掉），兩邊接在一起
 *    通過目前這個節點，正好對應「選這個節點當根、扣掉某一側葉子」的
 *    完整路徑，更新全域答案 ans。
 * 3. 同時更新這個節點要往上回傳的 maxSum1、maxSum2：
 *    maxSum1 = price[node] + max(所有子節點的 maxSum1, 0)
 *    maxSum2 = price[node] + max(所有子節點的 maxSum2, 0)
 *    （跟子節點比較時用 max(..., 0) 是因為節點也可以選擇「不往下延伸」，
 *    自己單獨成一條長度 1 的路徑）。
 * 4. 用鄰接表存樹（題目給的是邊列表），從任意節點（例如 0）當作 DFS
 *    起點即可，因為樹是連通的，起點選哪個不影響最終答案。
 */
class Solution {
 public:
  int longestPath(vector<int>& parent, string s) {
    const int n = parent.size();
    int ans = 1;
    vector<vector<int>> graph(n);

    for (int i = 1; i < n; ++i)
      graph[parent[i]].push_back(i);

    longestPathDownFrom(graph, 0, s, ans);
    return ans;
  }

 private:
  int longestPathDownFrom(const vector<vector<int>>& graph, int u,
                          const string& s, int& ans) {
    int max1 = 0;
    int max2 = 0;

    for (const int v : graph[u]) {
      const int res = longestPathDownFrom(graph, v, s, ans);
      if (s[u] == s[v])
        continue;
      if (res > max1) {
        max2 = max1;
        max1 = res;
      } else if (res > max2) {
        max2 = res;
      }
    }

    ans = max(ans, 1 + max1 + max2);
    return 1 + max1;
  }
};
