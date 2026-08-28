/**
 * 題目：1967. Number of Strings That Appear as Substrings in Word (作為子字串出現在單詞中的字串數目)
 * 難度：簡單 (Easy)
 * 描述：給定字串陣列 patterns 與字串 word，回傳 patterns 中有多少個字串
 *       是 word 的子字串。
 *
 * 時間複雜度：O(N*M)
 *             對每個 pattern 呼叫 find 進行子字串搜尋。
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 逐一檢查每個 pattern (Brute Force Substring Check)：
 *    - 走訪 patterns 中的每一個字串，直接利用 std::string::find 檢查它
 *      是否為 word 的子字串。
 * 2. 利用 string_view 避免額外複製 (Avoid Copies with string_view)：
 *    - 迴圈變數宣告為 const string_view&，每個 string 元素會隱式轉換成
 *      暫時的 string_view 並綁定到參照，不需要複製整個字串內容。
 * 3. 累加符合條件的數量：
 *    - 只要 word.find(pattern) 的結果不等於 npos（代表有找到），
 *      就將計數 count 加一，最終回傳總數。
 */
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for(const string& s : patterns) {
            if(word.contains(s)) ans++;
        }
        return ans;
    }
};
