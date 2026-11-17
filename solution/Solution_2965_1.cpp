/**
 * 題目：2965. Find Missing and Repeated Values
 * 難度：Easy
 * 描述：給定 n x n 的矩陣 grid，裡面的數字取自 1 ~ n²，
 *       其中恰好有一個數字出現兩次（重複），一個數字沒出現（缺失），其餘各出現一次。
 *       回傳 [重複的數字, 缺失的數字]。
 *
 * 分類主題：array-negative-marking
 * 技巧：以數值當索引並用負號標記找重複值, 用總和公式算缺失值, 累加時要取 abs 避免讀到已標負的格子
 *
 * 時間複雜度：O(n²)
 * 空間複雜度：O(1)（直接修改輸入矩陣，不計回傳）
 *
 * 解法思路：負數標記找重複值 + 總和公式算缺失值
 * 1. 數字範圍是 1 ~ n²，剛好對應矩陣 n² 個格子，
 *    數字 v 對應的索引是 idx = v - 1，座標為 (idx / n, idx % n)。
 * 2. 逐格讀取數字（用 abs，因為該格可能已被標成負數），到對應的格子看符號：
 *    - 已經是負數：代表這個數字之前出現過，就是重複值，記到 ans[0]。
 *    - 還是正數：第一次出現，把那一格改成負數作為標記。
 * 3. 同一趟迴圈累加每格的實際數值 sum（同樣要取 abs）。
 * 4. 缺失值用公式算：
 *    sum = (1 + 2 + ... + n²) + 重複值 - 缺失值
 *    ⇒ 缺失值 = n²(n² + 1) / 2 - (sum - 重複值)
 * 5. 因為缺失值用數學算出，不需要第二輪掃描找仍為正數的格子。
 * 6. 這份程式會修改輸入 grid，LeetCode 沒有限制，但若要求保持原樣，需要另外複製。
 */
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> ans(2);  // ans[0]：重複值，ans[1]：缺失值
        int sum = 0;         // 矩陣所有格子實際數值的總和
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int idx = abs(grid[i][j]) - 1;  // 數值對應的一維索引（取 abs，因為此格可能已被標負）
                sum += abs(grid[i][j]);         // 累加實際數值，不能加到被標負的值
                if(grid[idx / n][idx % n] < 0) {
                    ans[0] = idx + 1;           // 對應格已是負數，這個數字重複出現
                } else {
                    grid[idx / n][idx % n] = -grid[idx / n][idx % n];  // 第一次出現，標成負數
                }
            }
        }
        // 缺失值 = (1 ~ n² 的總和) - (sum 扣掉多出來的重複值)
        ans[1] = (1 + n * n) * (n * n) / 2 - (sum - ans[0]) ;
        return ans;
    }
};