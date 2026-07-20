/**
 * 題目：898. Bitwise ORs of Subarrays
 * 描述：給定一個整數陣列 arr，返回所有可能的子陣列位元 OR (Bitwise OR) 結果的數量。
 * 
 * 解法思路：
 * 1. 利用性質：當我們將一個新元素 a 加入前一個位置結尾的所有 OR 結果時，產生的新結果數量最多不超過 32 個（因為二進位位數最多 30 位，OR 運算只會讓 1 越來越多）。
 * 2. 使用 vector 紀錄所有累積的 OR 結果，並用 l 和 r 指標來區隔「上一輪產生的結果區間」。
 * 3. 對於每一個新元素 a：
 *    - 將 a 本身放入 s。
 *    - 走訪上一輪的區間 s[l ... r-1]，將每個舊結果與 a 做 `|` 運算，若不重複則加入 s。
 *    - 更新 l = r，進入下一輪。
 * 4. 最後透過 unordered_set 去重，計算總共有多少個不重複的 OR 結果。
 */

class Solution {
public:
    int subarrayBitwiseORs(std::vector<int>& arr) {
        std::vector<int> s;
        int l = 0;
        
        for (const int a : arr) {
            const int r = s.size();
            s.push_back(a); // 單獨以 a 結尾的子陣列
            
            // 結合上一輪的所有 OR 結果與當前元素 a
            for (int i = l; i < r; ++i) {
                if (s.back() != (s[i] | a)) {
                    s.push_back(s[i] | a);
                }
            }
            l = r; // 更新上一輪的結尾指標
        }

        // 將所有產生的結果放入 set 中去重，並回傳總數
        return std::unordered_set<int>(s.begin(), s.end()).size();
    }
};
