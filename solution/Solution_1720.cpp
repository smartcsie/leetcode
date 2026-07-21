/**
 * 題目：1720. Decode XORed Array
 * 描述：原陣列 arr 的長度為 n + 1，編碼陣列 encoded 的長度為 n。
 *       其中 encoded[i] = arr[i] ^ arr[i+1]。給定 encoded 與首項 first（即 arr[0]），
 *       請還原出原始的陣列 arr。
 * 
 * 解法思路：
 * 1. XOR 的可逆性性質：若 $A \oplus B = C$，則 $A \oplus C = B$。
 *    因此，由 `encoded[i] = arr[i] ^ arr[i+1]` 可以推導出：
 *    `arr[i+1] = arr[i] ^ encoded[i]`。
 * 2. 宣告一個 ans 陣列，並將已知的第一項 `first` 放入其中作為起點。
 * 3. 透過迴圈依序運算並將還原出來的後續元素推入 ans 陣列中。
 */

class Solution {
public:
    std::vector<int> decode(std::vector<int>& encoded, int first) {
        // 初始化答案陣列，放入已知的第一個元素
        std::vector<int> ans({first});
        
        // 依照公式 arr[i+1] = arr[i] ^ encoded[i] 逐步還原
        for (int i = 0; i < encoded.size(); i++) {
            ans.push_back(ans[i] ^ encoded[i]);
        }
        
        return ans;
    }
};
