/**
 * 題目：786. K-th Smallest Prime Fraction
 * 難度：Medium
 * 時間複雜度：O(N log(1/ε))，每次二分搜尋內的雙指標掃描是 O(N)，
 *             二分搜尋次數由 (right-left)/1e-9 的精度決定
 * 空間複雜度：O(1)
 * 分類主題：binary-search-on-answer
 *
 * 思路：
 * arr 已經是遞增排序，對任意 i < j，分數 arr[i]/arr[j] 都小於 1。
 * 不直接列舉所有 O(N^2) 個分數排序，而是「在答案值域上二分搜尋」：
 * 猜一個中間值 mid，數有多少個分數 <= mid，用這個數量跟 k 比較，
 * 來決定答案的真實值比 mid 大還是小，逐步縮小區間直到收斂。
 */
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double left = 0.0, right = 1.0;
        vector<int> ans = {0, 1}; // 預設答案

        // 對答案（分數的值）做二分搜尋，直到左右界收斂到幾乎相等
        while (right - left > 1e-9) {
            double mid = left + (right - left) / 2.0;
            int count = 0;
            int p = 0, q = 1; // 記錄目前看到、小於等於 mid 的分數中最大的那一個
            int i = 0;         // 雙指標：i 隨著 j 增加單調不減，不用每次從頭掃

            // 對每個分母 arr[j]，找出所有 arr[i] 使得 arr[i]/arr[j] <= mid
            // 也就是 arr[i] <= mid * arr[j]，因為 arr 遞增，i 只會往右移動
            for (int j = 1; j < n; ++j) {
                while (i < n && arr[i] <= mid * arr[j]) {
                    i++;
                }
                count += i; // 分母是 arr[j] 時，有 i 個分子能讓分數 <= mid，累加總數

                // arr[i-1]/arr[j] 是目前這個分母下最接近 mid（但不超過）的分數；
                // 用交叉相乘 arr[i-1]*q > p*arr[j] 比較兩個分數大小，避免除法的精度誤差，
                // 更新成目前看過的所有分數裡最大的那一個
                if (i > 0 && arr[i - 1] * q > p * arr[j]) {
                    p = arr[i - 1];
                    q = arr[j];
                }
            }

            if (count < k) {
                left = mid; // 小於等於 mid 的分數不夠 k 個，代表第 k 小的分數比 mid 大，往右搜
            } else {
                // 小於等於 mid 的分數已經 >= k 個，代表第 k 小的分數 <= mid，
                // 先把目前找到的候選答案記下來，再往左收斂，看能不能找到更精確、更小的範圍
                right = mid;
                ans = {p, q};
            }
        }

        return ans;
    }
};