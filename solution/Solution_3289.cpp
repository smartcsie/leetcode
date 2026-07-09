/**
 * 題目：3289. The Two Sneaky Numbers of Digitville
 * 難度：簡單 (Easy)
 * 描述：在包含 0 到 n-1 數字的陣列中，找出兩個出現兩次的數字。
 * * 優化重點：
 * 1. 空間效率：使用 bitset 代替 bool 陣列或 unordered_map，空間佔用極小。
 * 2. 高速存取：bitset 的 test 與 set 操作均為 O(1) 指令級運算，速度極快。
 */

class Solution {
public:
    std::vector<int> getSneakyNumbers(std::vector<int>& nums) {
        // 題目限制範圍內數字，bitset 大小需大於數字上限
        std::bitset<200> seen; 
        std::vector<int> res;
        
        for (const int& num : nums) {
            if (!seen.test(num)) {
                seen.set(num);
            } else {
                res.push_back(num);
            }
        }
        return res;
    }
};
