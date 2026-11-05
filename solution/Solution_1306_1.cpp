/**
 * 題目：1306. Jump Game III
 * 難度：中等 (Medium)
 * 描述：給定一個非負整數陣列 arr 和起始位置 start，每次可以從當前位置 i
 * 跳到 i + arr[i] 或 i - arr[i]，判斷是否能跳到值為 0 的位置。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （DFS 遞迴）：
 * 1. 從 start 開始做 DFS，每次往 cur + arr[cur] 和 cur - arr[cur] 兩個方向跳。
 * 2. 若當前位置越界或已訪問，回傳 false。
 * 3. 若當前位置值為 0，回傳 true。
 * 4. 標記當前位置為已訪問後，遞迴探索兩個方向，取 OR 結果。
 *
 * 與 BFS 版本的差異：
 * DFS 版程式碼更簡潔，但最壞情況下遞迴深度為 O(N)，
 * 可能造成 stack overflow；BFS 版則不受此限制。
 */
class Solution {
private:
    bool canReach(vector<int>& arr, int cur, vector<bool>& seen) {
        if (cur < 0 || cur >= (int)seen.size()) return false;
        if (seen[cur]) return false;
        if (arr[cur] == 0) return true;
        seen[cur] = true;
        return canReach(arr, cur + arr[cur], seen) ||
               canReach(arr, cur - arr[cur], seen);
    }
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> seen(arr.size());
        return canReach(arr, start, seen);
    }
};