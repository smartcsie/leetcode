/**
 * 題目：1636. Sort Array by Increasing Frequency (按照頻率將陣列升序排序)
 * 難度：簡單 (Easy)
 * 描述：根據元素的頻率進行升序排序，若頻率相同，則按數值降序排序。
 * * 時間複雜度：O(N log N) - 主要開銷在於排序，統計頻率為 O(N)。
 * 空間複雜度：O(1) - 使用固定大小陣列空間 (201 為常數)。
 * * 優化點：
 * 1. 使用常數陣列減少記憶體頻繁存取。
 * 2. 透過 Lambda 內直接提取頻率變數，減少對陣列的重複計算。
 */

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int count[201] = {0};
        for(const int& num : nums) {
            count[num+100]++;
        }
        sort(nums.begin(), nums.end(), [&](const int a, const int b) {
            return count[a+100] != count[b+100] ? count[a+100] < count[b+100] : a > b;
        });
        return nums;
    }
};
