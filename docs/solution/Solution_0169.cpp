/**
 * 題目：169. Majority Element (多數元素)
 * 難度：簡單 (Easy)
 * 描述：找出陣列中出現次數超過 ⌊n/2⌋ 的元素。
 * * 時間複雜度：O(N) - 只需遍歷一次陣列。
 * 空間複雜度：O(1) - 僅使用兩個變數。
 * * 優化思路 (Boyer-Moore Voting Algorithm)：
 * 將第一個元素視為候選人，當遇到相同元素則 `count++`，遇到不同元素則 `count--`。
 * 當 `count` 歸零時，代表目前的候選人已被「抵消」，將當前數字設為新候選人。
 * 由於多數元素出現次數超過一半，最後剩下的候選人必定為答案。
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        
        for (int num : nums) {
            // 當計數器為 0，更換新的候選人
            if (count == 0) {
                candidate = num;
            }
            
            // 若 num 與候選人相同則加分，不同則扣分
            count += (num == candidate) ? 1 : -1;
        }
        
        return candidate;
    }
};
