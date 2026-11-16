/**
 * 題目：1437. Check If All 1's Are at Least Length K Places Away
 * 難度：簡單 (Easy)
 * 描述：給定一個二進位陣列 nums 和整數 k，判斷所有的 1 之間是否至少相距 k 個位置。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （Linear Scan，計算相鄰兩個 1 之間的 0 個數）：
 * 1. count 初始為 k，代表「上一個 1 之前已有足夠間距」，避免對第一個 1 特判。
 * 2. 遇到 0：count++（間距增加）。
 * 3. 遇到 1：
 *    - 若 count < k：兩個 1 之間的距離不足，回傳 false。
 *    - 否則：重置 count = 0，開始計算下一段間距。
 */
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        for (int i = 0, count = k; i < (int)nums.size(); i++) {
            if (nums[i] == 0) {
                count++;
            } else {
                if (count < k) return false;
                count = 0;
            }
        }
        return true;
    }
};