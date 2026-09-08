/**
 * 題目：3304. Find the K-th Character in String Game I
 * 難度：簡單 (Easy)
 * 描述：字串從 "a" 開始，每一輪將原字串複製並將每個字元後移一位（'a'->'b' 等），
 * 最終找出第 k 個字元。
 * 優化重點：
 * 1. 模擬生成：利用迴圈逐步擴充字串。
 * 2. 次數控制：因為長度呈指數增長，只需進行 ceil(log2(k)) 次操作即可覆蓋第 k 個位置。
 *
 * 時間複雜度：O(K)
 * 空間複雜度：O(K)
 */

class Solution {
public:
    char kthCharacter(int k) {
        int times = static_cast<int>(ceil(log2(k)));
        string s = "a";
        for(int i = 0; i < times; i++) {
            int n = s.size();
            for(int j = 0; j < n; j++) {
                char c = (s[j] == 'z') ? 'a' : s[j] + 1;
                s.push_back(c);
            }
        }
        return s[k - 1];
    }
};
