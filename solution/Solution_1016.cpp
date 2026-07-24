/**
 * 題目：1016. Binary String With Substrings Representing 1 To N
 * 描述：給定一個二進位字串 s 和一個正整數 n。
 *       如果從 1 到 n 的每個整數的二進位表示形式都是 s 的子字串，則返回 true，否則返回 false。
 * 
 * 解法思路：
 * 1. 邊界剪枝（Math Pruning）：
 *    - 一個長度為 M 的字串 `s` 最多只能包含不同長度的子字串，且最大可能的 N 有其實際物理限制。
 *    - 當 N 超過一定範圍（此處為 1511，因字串長度上限或位元組限制），不可能在合理長度的字串中包含所有二進位，直接返回 false。
 * 2. 逆向迴圈與子字串包含性質：
 *    - 不需要從 1 檢查到 N。如果大數字（例如介於 `n` 到 `n/2 + 1` 之間）的二進位字串存在於 `s` 中，
 *      通常其右側截斷的小數字也必然存在（或是透過檢查後半段即可涵蓋所有必要條件）。
 * 3. 實作細節：
 *    - 使用 `std::bitset<32>` 將整數轉換為 32 位元二進位字串。
 *    - 利用 `substr(binary.find("1"))` 去除前導零。
 *    - 使用 `s.find(binary)` 檢查該二進位字串是否存在於 `s` 中。
 */

class Solution {
public:
    bool queryString(std::string s, int n) {
        // 1. 剪枝：若 n 超過合理範圍直接返回 false
        if (n > 1511) {
            return false;
        }
        
        // 2. 從 n 反向檢查到 n / 2 + 1
        for (int i = n; i > n / 2; --i) {
            std::string binary = std::bitset<32>(i).to_string();
            // 移除前導零
            binary = binary.substr(binary.find("1"));
            
            // 若 s 中找不到該二進位字串，返回 false
            if (s.find(binary) == std::string::npos) {
                return false;
            }
        }
        
        return true;
    }
};
