/**
 * 題目：1013. Partition Array Into Three Parts With Equal Sum
 * 描述：給你一個整數陣列 arr，如果可以把它分成三個非空且和相等的連續子陣列，
 *       就返回 true，否則返回 false。
 * 
 * 解法思路：
 * 1. 計算整個陣列的總和 sum。如果總和不能被 3 整除（sum % 3 != 0），
 *    絕對無法均分成三份，直接返回 false。
 * 2. 每份的目標和為 target = sum / 3。
 * 3. 走訪陣列，用 partial 累積當前子陣列的和：
 *    - 當 partial 達到 target 時，代表找到了一份，將計數器 parts 加 1，
 *      並將 partial 重置為 0 以準備尋找下一份。
 * 4. 注意：題目要求分成「三部分」，但如果前面已經集滿了三部分，
 *    剩下的數字如果全部加到最後（可能因為陣列後面有許多 0），parts 可能會 >= 3。
 *    因此只要最後 parts >= 3 即可判定成功（特別是當 target 為 0 時）。
 */

class Solution {
public:
    bool canThreePartsEqualSum(std::vector<int>& arr) {
        // 1. 計算總和
        int sum = std::accumulate(arr.begin(), arr.end(), 0);
        
        // 2. 若總和無法被 3 整除，直接回傳 false
        if (sum % 3 != 0) {
            return false;
        }
        
        int target = sum / 3;
        int parts = 0;
        int partial = 0;
        
        // 3. 走訪陣列計算符合 target 的段落數
        for (const int& num : arr) {
            partial += num;
            if (partial == target) {
                parts++;
                partial = 0; // 重置以計算下一段
            }
        }
        
        // 4. 必須至少找到 3 個符合條件的段落
        return parts >= 3;
    }
};
