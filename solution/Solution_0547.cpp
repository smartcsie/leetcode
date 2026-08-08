/**
 * 題目：547. Number of Provinces
 * 難度：中等 (Medium)
 * 描述：給定一個 n x n 的鄰接矩陣 isConnected，isConnected[i][j] = 1 代表
 * 城市 i 與城市 j 直接相連。省份是一組直接或間接相連的城市所構成的集合，
 * 請回傳省份的總數。
 *
 * 時間複雜度：O(N²·α(N)) - 需雙重迴圈遍歷 n x n 鄰接矩陣（上三角，含對角線），
 *             每次呼叫 union 操作的均攤時間複雜度為反阿克曼函數 α(N)，近似常數。
 * 空間複雜度：O(N) - id 與 rank 兩個陣列各佔用 O(N) 空間。
 *
 * 解法思路：
 * （並查集 Union-Find，按秩合併 + 路徑壓縮）：
 * 1. 初始化 Union-Find：
 * - id[i] 初始指向自己（iota 初始化），rank 全為 0，count 初始為 n
 *   （代表一開始每個城市都是獨立的省份）。
 * 2. 遍歷鄰接矩陣做合併：
 * - 只需掃描上三角（j 從 i 開始），isConnected[i][j] == 1 時呼叫
 *   unionByRank(i, j) 合併兩個城市所屬的集合。
 * 3. 按秩合併（Union by Rank）：
 * - 比較兩個根節點的 rank，把樹高較矮的接到樹高較高的下面，避免樹退化成
 *   鏈狀，若兩者 rank 相同則任選一邊接上並將該邊 rank + 1。
 * - 每成功合併一次，count（目前獨立集合數）就減一。
 * 4. 路徑壓縮（Path Compression）：
 * - find(u) 遞迴找根節點的同時，把沿途經過的節點直接指向根節點
 *   （id[u] == u ? u : id[u] = find(id[u])），加速未來查詢。
 * 5. 回傳結果：
 * - getCount() 回傳最終的獨立集合數，也就是省份總數。
 */
class UnionFind {
public:
    UnionFind(int n) : count(n), id(n), rank(n) {
        iota(id.begin(), id.end(), 0);
    }

    void unionByRank(int u, int v) {
        const int i = find(u);
        const int j = find(v);
        if (i == j)
            return;
        if (rank[i] < rank[j]) {
        id[i] = j;
        } else if (rank[i] > rank[j]) {
            id[j] = i;
        } else {
            id[i] = j;
            ++rank[j];
        }
        --count;
    }

    int getCount() const {
        return count;
    }

private:
    int count;
    vector<int> id;
    vector<int> rank;

    int find(int u) {
        return id[u] == u ? u : id[u] = find(id[u]);
    }
};

class Solution {
    public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        const int n = isConnected.size();
        UnionFind uf(n);

        for (int i = 0; i < n; ++i)
            for (int j = i; j < n; ++j)
                if (isConnected[i][j] == 1)
                    uf.unionByRank(i, j);

        return uf.getCount();
    }
};
