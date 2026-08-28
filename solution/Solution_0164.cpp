/**
 * 題目：164. Maximum Gap (最大間距)
 * 難度：困難 (Hard)
 * 描述：給定整數陣列 nums，回傳其排序後相鄰元素之間的最大差值；
 *       若陣列元素少於兩個，回傳 0。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 1. 鴿籠原理：決定桶的大小 (Pigeonhole Principle for Bucket Size)：
 *    - 若將 [min, max] 這個範圍平均分成 (N-1) 個桶，
 *      根據鴿籠原理，答案（最大間距）不可能發生在「同一個桶內部」，
 *      因為每個桶的寬度必定小於等於平均間距，所以真正的最大間距只可能出現在「跨桶」之間。
 * 2. 計算桶的大小與數量：
 *    - bucketSize = max(1, (mx - mn) / (n - 1))，用 max 1 避免所有數字相同時桶大小為 0。
 *    - 桶的數量則依據數值範圍與桶大小反推。
 * 3. 只需記錄每個桶的「最小值」與「最大值」：
 *    - 不需要把每個桶內的完整資料都存起來，因為同一桶內的間距不可能是答案，
 *      只需要知道每個桶的邊界值，就足以算出跨桶的間距。
 * 4. 只比較「相鄰非空桶」之間的邊界 (Compare Adjacent Non-Empty Buckets)：
 *    - 依序走訪所有桶，用 prevMax 記錄上一個非空桶的最大值，
 *      跳過空桶，計算目前桶的最小值與 prevMax 的差距，取最大值即為答案。
 * 5. 邊界情況：
 *    - 元素少於 2 個，或所有元素相同（mn == mx），直接回傳 0。
 */
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        if (mn == mx) return 0;

        // 桶的大小：確保「同一個桶內」的最大間距一定小於答案，答案只可能出現在跨桶之間
        int bucketSize = max(1, (mx - mn) / (n - 1));
        int bucketCount = (mx - mn) / bucketSize + 1;

        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);

        for (int num : nums) {
            int idx = (num - mn) / bucketSize;
            bucketMin[idx] = min(bucketMin[idx], num);
            bucketMax[idx] = max(bucketMax[idx], num);
        }

        int maxGap = 0;
        int prevMax = mn;
        for (int i = 0; i < bucketCount; i++) {
            if (bucketMin[i] == INT_MAX) continue;
            maxGap = max(maxGap, bucketMin[i] - prevMax);
            prevMax = bucketMax[i];
        }
        return maxGap;
    }
};
