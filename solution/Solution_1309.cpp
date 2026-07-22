/**
 * 題目：1309. Decrypt String from Alphabet to Integer Mapping
 * 描述：給定一個字串 s，由數字（'0'-'9'）和 '#' 組成。映射規則如下：
 *       - '1' 到 '9' 分別對應 'a' 到 'i'。
 *       - '10#' 到 '26#' 分別對應 'j' 到 'z'。
 *       返回解密後的字串。
 * 
 * 解法思路：
 * 1. 建立一個雜湊表（unordered_map），將所有的加密代碼（如 "1", "2", ..., "10#", "26#"）
 *    與對應的英文字母進行映射。
 * 2. 從左到右走訪字串 s：
 *    - 檢查當前字元後面兩位（即 i + 2）是否有 '#'。
 *    - 如果有，代表這是 10# 到 26# 的字元，截取 3 個字元（s.substr(i, 3)）進行對應解密，並將 i 向後移動 2 位。
 *    - 如果沒有，代表這是 1 到 9 的單位數字元，直接解密當前單一字元。
 * 3. 將解密後的字元拼接到答案字串 ans 中並回傳。
 */

class Solution {
public:
    std::string freqAlphabets(std::string s) {
        std::unordered_map<std::string, char> map;
        
        // 建立 'a' 到 'i' 的映射 ("1" 到 "9")
        for (char c = 'a'; c <= 'i'; c++) {
            map[std::string(1, c - 'a' + '1')] = c;
        }
        
        // 建立 'j' 到 'z' 的映射 ("10#" 到 "26#")
        for (char c = 'j'; c <= 'z'; c++) {
            map[std::to_string(c - 'j' + 10) + "#"] = c;
        }
        
        std::string ans;
        for (int i = 0; i < s.size(); i++) {
            // 向後檢查兩位是否為 '#' (即形如 "10#" ~ "26#")
            if ((i + 2) < s.size() && s[i + 2] == '#') {
                ans += map[s.substr(i, 3)];
                i += 2; // 跳過已處理的 '#' 與數字
            } else {
                ans.push_back(map[std::string(1, s[i])]);
            }
        }
        
        return ans;
    }
};
