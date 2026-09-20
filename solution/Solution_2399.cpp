/**
 * 題目：2399. Check Distances Between Same Letters
 * 難度：簡單 (Easy)
 * 描述：給你一個下標從 0 開始的字串 s，其中包含字母表中所有字元恰好各出現兩次。
 * 另給你一個長度為 26 的陣列 distance。
 * 如果對於字串中每個在 s 中出現兩次的字母，它們兩次出現位置之間夾著的字元數
 * 剛好等於 distance[idx]，則返回 true，否則返回 false。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 使用單一追蹤陣列：
 * - 建立一個大小為 26、初始值全為 -1 的陣列 `first`，用來記錄每一個字母（'a'-'z'）第一次出現的索引位置。
 * 2. 單次走訪（Single-Pass）：
 * - 當遇到字元 `s[i]` 時，計算其字母索引 `idx = s[i] - 'a'`。
 * - 若 `first[idx] == -1`，代表這是該字母第一次出現，記錄其位置 `first[idx] = i`。
 * - 若 `first[idx] != -1`，代表這是該字母第二次出現：
 * - 夾著的字元數即為當前位置與首次位置的差值減一：`i - first[idx] - 1`。
 * - 立即檢查該距離是否與 `distance[idx]` 相符，若不合直接返回 false（Early Exit）。
 * 3. 走訪完成若無異常，返回 true。
 */

class Solution {
public:
    bool checkDistances(std::string s, std::vector<int>& distance) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);
        int n = s.size();
        for(int i = 0, j = n - 1; i < n && j >= 0; i++, j--) {
            if(first[s[i] - 'a'] == - 1) first[s[i] - 'a'] = i;
            if(last[s[j] - 'a'] == - 1) last[s[j] - 'a'] = j;
        }
        for(int i = 0; i < 26; i++) {
            if(last[i]!= -1 && first[i] != - 1 && (last[i] - first[i] - 1) != distance[i]) return false;
        }
        return true;
    }
};
