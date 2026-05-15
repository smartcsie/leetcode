/**
 * 題目：454. 4Sum II (四數相加 II)
 * 難度：中等 (Medium)
 * 描述：給定四個整數陣列 nums1, nums2, nums3, nums4，長度均為 n。
 *      找出有多少個元組 (i, j, k, l) 滿足：
 *      nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 * 
 * 時間複雜度：O(n²) - 拆分為兩組，每組雙層迴圈 O(n²)。
 * 空間複雜度：O(n²) - 最壞情況下，兩數之和的組合種類可能有 n² 種。
 * 
 * 解法思路：
 * 1. 將四個陣列分為兩組：(nums1, nums2) 與 (nums3, nums4)。
 * 2. 先遍歷第一組，計算所有可能的 nums1[i] + nums2[j] 之和，並將結果存入 unordered_map 中，
 *    Key 為和，Value 為該和出現的次數。
 * 3. 接著遍歷第二組，計算 nums3[k] + nums4[l] 的和。
 * 4. 如果 -(nums3[k] + nums4[l]) 存在於 Map 中，則代表找到了符合條件的組合，
 *    將 Map 中對應的次數累加到結果中。
 */

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> map;
        int res = 0;
        for(int num1 : nums1) {
            for(int num2 : nums2) {
                map[num1+num2]++;
            }
        }

        for(int num3 : nums3) {
            for(int num4 : nums4) {
                if(map.find(-num3-num4) != map.end()) {
                    res += map[-num3-num4];
                }
            }
        }

        return res;
    }
};
