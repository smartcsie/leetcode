/**
 * 題目：217. Contains Duplicate
 * 描述：給你一個整數陣列 nums。如果任一值在陣列中出現至少兩次，返回 true；如果陣列中每個元素互不相同，返回 false。
 * 
 * 解法思路（雜湊集合雜湊法 Hash Set）：
 * 1. 利用 `std::unordered_set` 的特性：
 *    - 雜湊集合（Set）只會儲存不重複的元素。當我們把整個 `nums` 陣列直接傳入建構子初始化 `unordered_set` 時，所有重複的元素會自動被過濾掉。
 * 2. 比較大小：
 *    - 比較集合的大小（`unique.size()`）與原本陣列的大小（`nums.size()`）。如果集合的元素個數小於原本的陣列長度，代表陣列中存在重複的元素，返回 `true`；否則返回 `false`。
 */

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        // 利用 unordered_set 自動去除重複元素的特性
        std::unordered_set<int> unique(nums.begin(), nums.end());
        
        // 若集合大小小於原陣列大小，代表有重複元素
        return unique.size() < nums.size();
    }
};
