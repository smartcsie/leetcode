/**
 * 題目：1399. Count Largest Group (統計最大分組的數目)
 * 難度：簡單 (Easy)
 * 描述：給定整數 n，將 1 到 n 之間的每個數字，依照其「各位數字之和」分組，
 *       回傳擁有最多數字的分組（最大分組）有幾個（可能同時存在多個大小並列最大的分組）。
 *
 * 時間複雜度：O(N * D) - N 為範圍大小，D 為位數（視為常數，通常不超過 5），
 *             整體近似 O(N)。
 * 空間複雜度：O(1) - groups 陣列大小固定為 37（位數和最大可能值 + 1），不隨 N 成長。
 *
 * 解法思路：
 * 1. 固定大小的計數陣列作為分組容器 (Fixed-Size Bucket by Digit Sum)：
 *    - 由於 n 的範圍有限，位數和的最大可能值也有上限（例如 9999 的位數和為 36），
 *      可以直接用大小 37 的陣列 groups，以位數和當作索引直接計數，不需要雜湊表。
 * 2. 逐一計算每個數字的位數和並累加分組計數：
 *    - 對 1 到 n 的每個數字，透過反覆取餘數（% 10）與整除（/ 10）算出其位數和，
 *      並將對應分組的計數加一。
 * 3. 同步追蹤目前最大的分組人數：
 *    - 每次更新分組計數時，順便更新 maxFreq，記錄目前為止「單一分組」的最大數字個數。
 * 4. 統計有多少個分組達到這個最大值：
 *    - 走訪完所有數字後，用 std::count 統計 groups 陣列中，
 *      有多少個分組的計數恰好等於 maxFreq，即為答案（可能有多個分組並列最大）。
 */
class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> groups(37);
        int maxFreq = 0;
        for(int i = 1; i <= n; i++) {
            int t = i;
            int sum = 0;
            while(t > 0) {
                sum += t % 10;
                t /= 10;
            }
            groups[sum]++;
            maxFreq = max(maxFreq, groups[sum]);
        }
        return count(groups.begin(), groups.end(), maxFreq);
    }
};
