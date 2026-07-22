/**
 * 題目：2138. Divide a String Into Groups of Size k
 * 描述：將字串 s 分割成多個長度為 k 的群組。若最後一個群組長度不足 k，
 *       則用字元 fill 填滿。返回包含所有群組的 vector<string>。
 * 
 * 解法思路：
 * 1. 利用向上取整公式 `(n + k - 1) / k` 計算總共會被分成多少個群組（segs）。
 * 2. 建立一個大小為 segs 的 vector<string>，且每個字串預先初始化為長度 k 的空白字串。
 * 3. 走訪字串 s 的每一個字元，透過 `i / k` 決定它是第幾個群組，`i % k` 決定它在群組中的位置，
 *    直接將字元填入對應的二維座標 `ans[i / k][i % k]`。
 * 4. 針對最後一個群組（`ans[segs - 1]`），檢查是否有未被填滿的空白字元，若有則全數替換為 fill。
 */

class Solution {
public:
    std::vector<std::string> divideString(std::string s, int k, char fill) {
        int n = s.size();
        
        // 1. 計算總群組數（向上取整）
        int segs = (n + k - 1) / k;
        
        // 2. 初始化結果 vector，每組長度為 k，先用空白 ' ' 填滿
        std::vector<std::string> ans(segs, std::string(k, ' '));
        
        // 3. 將原字串的字元對應填入二維網格中
        for (int i = 0; i < n; i++) {
            ans[i / k][i % k] = s[i];
        }
        
        // 4. 檢查最後一個群組，將不足的空白位置補上 fill
        for (char& c : ans[segs - 1]) {
            if (c == ' ') {
                c = fill;
            }
        }
        
        return ans;
    }
};
