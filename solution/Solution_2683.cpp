/**
 * 題目：2683. Neighboring Bitwise XOR
 * 描述：給定一個一維陣列 derived，代表某個隱藏原陣列 original 的相鄰互斥或結果。
 *       檢查是否存在一個合法的原始二進位陣列 original。
 * 
 * 解法思路：
 * 1. 根據定義：derived[i] = original[i] ^ original[(i + 1) % n]。
 * 2. 如果我們對 derived 中所有元素進行連續的 XOR 運算：
 *    - 展開後會發現每一個 original[i] 都剛好出現了兩次。
 *    - 根據 XOR 的反身性與消去律（x ^ x = 0），所有 original 元素都會互相抵消。
 * 3. 因此，若總 XOR 和為 0（即 ans == 0 / true），代表存在合法解；否則無解。
 */

class Solution {
public:
    bool doesValidArrayExist(std::vector<int>& derived) {
        bool ans = true; // 初始布林值代表累積的 XOR 結果為 0 (false 的反向或直接用 int 亦可)
        
        for (const int& bit : derived) {
            ans ^= bit; // 持續進行 XOR 運算
        }
        
        // 若最後 ans 為 true（等同於最終 XOR 結果為 0），代表合法
        return ans;
    }
};
