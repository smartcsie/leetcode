/**
 * 題目：2150. Find All Lonely Numbers in the Array (找出陣列中的所有孤獨數字)
 * 難度：中等 (Medium)
 * 描述：如果一個數字 x 在陣列中僅出現一次，且 x-1 和 x+1 均未在陣列中出現，則稱其為「孤獨數字」。
 *      回傳陣列中的所有孤獨數字。
 * 
 * 時間複雜度：O(n) - 遍歷一次陣列建立哈希表，再遍歷一次檢查條件。
 * 空間複雜度：O(n) - 需要空間儲存所有數字的頻率。
 * 
 * 解法思路：
 * 1. 使用 unordered_map<int, int> 紀錄陣列中每個數字出現的次數。
 * 2. 再次遍歷哈希表中的每一個鍵值對 (num, count)：
 *    - 檢查 count 是否等於 1（只出現一次）。
 *    - 檢查 num - 1 是否存在於 map 中。
 *    - 檢查 num + 1 是否存在於 map 中。
 * 3. 若以上三項檢查皆通過（count == 1 且鄰居不存在），則該數為孤獨數字。
 */

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> count;
        vector<int> res;
        for(int num: nums) {
            count[num]++;
        }
        for(int num: nums) {
            if(!count.contains(num-1) && count[num] <= 1 && !count.contains(num+1))
                res.push_back(num);
        }
        return res;
    }
};
