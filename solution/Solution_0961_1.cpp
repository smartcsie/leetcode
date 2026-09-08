/**
 * 題目：961. N-Repeated Element in Size 2N Array
 * 難度：簡單 (Easy)
 * 描述：在長度為 2N 的陣列中，有一個元素重複 N 次，找出該元素。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （unordered_set）：
 * 逐一插入 set，第一個插入失敗（已存在）的元素即為重複 N 次的元素。
 */
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> sets;
        for(const int& x : nums) {
            if(!sets.insert(x).second)  return x;
        }
        return -1;
    }
};