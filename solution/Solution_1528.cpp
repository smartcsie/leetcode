/**
 * 題目：1528. Shuffle String (重新排列字串)
 * 難度：簡單 (Easy)
 * 描述：根據 indices 將 s 中的字元重新排列。
 * * 時間複雜度：O(N) - 遍歷一次字串。
 * 空間複雜度：O(N) - 為了存放結果字串。
 * * 設計思路：
 * 建立一個同樣長度的新字串，並利用 `indices` 陣列作為映射表，
 * 直接將 `s[i]` 放到目標位置 `res[indices[i]]`。
 */

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        // 預先分配空間以減少記憶體重新配置
        string res(s.size(), ' ');
        
        // 利用索引對應關係直接定位
        for (size_t i = 0; i < s.size(); ++i) {
            res[indices[i]] = s[i];
        }
        
        return res;
    }
};
