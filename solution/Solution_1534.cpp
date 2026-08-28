/**
 * 題目：1534. Count Good Triplets (計算好三元組數目)
 * 難度：簡單 (Easy)
 * 描述：給定整數陣列 arr 與三個整數 a、b、c，統計滿足以下條件的三元組 (i, j, k) 數量：
 *       0 <= i < j < k < arr.length，且 |arr[i]-arr[j]| <= a、|arr[j]-arr[k]| <= b、
 *       |arr[i]-arr[k]| <= c 同時成立。
 *
 * 時間複雜度：O(N³)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 暴力窮舉所有三元組 (Brute Force Enumeration)：
 *    - 由於題目資料規模通常很小（N 通常不超過幾百），直接用三層迴圈窮舉
 *      所有滿足 i < j < k 的索引組合即可，不需要額外的優化。
 * 2. 逐一驗證三個條件：
 *    - 對每組 (i, j, k)，分別檢查 arr[i] 與 arr[j]、arr[j] 與 arr[k]、
 *      arr[i] 與 arr[k] 之間的絕對差值，是否都落在對應的門檻 a、b、c 之內。
 * 3. 三個條件同時成立才計數：
 *    - 只有當三個絕對差值條件全部滿足時，才將這組三元組計入答案 ans。
 */
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int ans = 0;
        for(int i = 0 ;i < n; i++) {
            for(int j = i + 1 ;j < n; j++) {
                for(int k = j + 1 ;k < n; k++) {
                    if( abs((arr[i] - arr[j])) <= a &&
                        abs((arr[j] - arr[k])) <= b &&
                        abs((arr[i] - arr[k])) <= c ) ans++;
                }
            }
        }
        return ans;
    }
};
