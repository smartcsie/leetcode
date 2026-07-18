/**
 * 題目：168. Excel Sheet Column Title
 * 描述：給定一個數字，返回其對應的 Excel 欄位名稱 (例如 1 -> "A", 28 -> "AB")。
 * 
 * 解法思路：
 * 1. 這是個 26 進位轉換問題，但由於 Excel 欄位沒有 "0"，而是從 1 到 26 (A-Z)。
 * 2. 為了處理這個偏移，我們在每一輪除法前先將 columnNumber 減 1。
 * 3. 這樣一來，原本 1-26 的範圍變成了 0-25，可以直接對應 'A'-'Z'。
 * 4. 最後將字串反轉即可得到結果。
 */

class Solution {
public:
    std::string convertToTitle(int columnNumber) {
        std::string ans;
        int n = columnNumber;
        
        while (n > 0) {
            n--; // 先減 1，將 1-26 映射為 0-25
            ans.push_back((n % 26) + 'A');
            n /= 26;
        }
        
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
