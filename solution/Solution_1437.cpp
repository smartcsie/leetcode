/**
 * 題目：1437. Check If All 1's Are at Least Length K Places Away
 * 描述：給你一個由若干 0 和 1 組成的二進位陣列 nums 以及整數 k。
 *       如果所有 1 之間至少相隔 k 個元素（即每個 1 之間的距離至少為 k），
 *       請返回 true；否則返回 false。
 * 
 * 解法思路：
 * 1. 使用變數 `pos` 來記錄上一個出現 `1` 的索引位置，初始值設為 `-1`。
 * 2. 走訪整個陣列：
 *    - 當遇到 `nums[i] == 1` 時：
 *      - 檢查是否已經存在前一個 `1`（即 `pos != -1`）。
 *      - 計算兩者之間的距離（`i - pos - 1`）。若距離小於 `k`，代表不符合條件，直接回傳 `false`。
 *      - 更新 `pos = i`。
 * 3. 若完整走訪完都沒違規，則回傳 `true`。
 */

class Solution {
public:
    bool kLengthApart(std::vector<int>& nums, int k) {
        int pos = -1; // 記錄上一個 1 的位置
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                // 如果不是第一個遇到的 1，檢查與前一個 1 的距離是否小於 k
                if (pos != -1 && (i - pos - 1) < k) {
                    return false;
                }
                // 更新位置
                pos = i;
            }
        }
        
        return true;
    }
};
