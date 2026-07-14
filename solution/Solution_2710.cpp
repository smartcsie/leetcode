/**
 * 題目：2710. Remove Trailing Zeros From a String
 * 難度：簡單 (Easy)
 * 描述：移除字串表示的整數末尾的所有零。
 * * 時間複雜度：O(N) - N 為字串長度，最壞情況遍歷整字串。
 * 空間複雜度：O(1) - 若原地修改，否則為 O(N) 返回新字串。
 * * 解法思路：
 * 方案一 (Pop back)：使用 `pop_back()` 直接刪除末尾的 '0'，直到遇到非 '0' 字元。
 * 方案二 (Substr)：找到最後一個非零字元的位置，直接截取子字串。
 */


class Solution {
public:
    std::string removeTrailingZeros(std::string num) {
        // 使用 pop_back 直接修改，無需額外空間分配
        while (!num.empty() && num.back() == '0') {
            num.pop_back();
        }
        return num;
    }
};
