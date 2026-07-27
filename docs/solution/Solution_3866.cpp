/**
 * 題目：3866. First Unique Even Element (第一個唯一的偶數元素)
 * 難度：簡單 (Easy)
 * 描述：在陣列 nums 中找出第一個出現頻率恰好為 1 的偶數。
 * * 時間複雜度：O(N) - 兩次遍歷陣列。
 * 空間複雜度：O(1) - 使用固定大小的 101 個空間。
 * * 優化思路：
 * 1. 記憶體效率：利用 Stack 上的固定陣列，避免 Heap 配置與雜湊開銷。
 * 2. 效能平衡：位元運算 `(num & 1) == 0` 是檢查偶數的最快指令。
 */

class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int seen[101] = {0};
        for(const int& num : nums) {
            if((num & 1) == 0) seen[num]++;
        }
        for(const int& num : nums) {
            if(seen[num] == 1) return num;
        } 
        return -1;
    }
};
