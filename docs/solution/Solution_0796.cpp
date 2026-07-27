/**
 * 題目：796. Rotate String (旋轉字串)
 * 難度：簡單 (Easy)
 * 描述：檢查字串 s 是否能透過旋轉變成字串 goal。
 * * 時間複雜度：O(N) - 取決於字串搜尋演算法 (通常為 KMP 或更優)，N 為字串長度。
 * 空間複雜度：O(N) - 用於儲存 s + s 的新字串。
 * * 優化思路：
 * 任何一個由 s 旋轉得到的字串，必然會出現在 s + s 的子字串中。
 * 例如：s = "abcde", s + s = "abcdeabcde"。
 * 旋轉結果 "cdeab" 確實包含在其中。
 */

#include <string>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        // 若長度不等，絕對不可能透過旋轉達成
        // 接著檢查 goal 是否為 s + s 的一部分
        return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
};
