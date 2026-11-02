/**
 * 題目：748. Shortest Completing Word
 * 難度：Easy
 * 時間複雜度：O(L + W)，L 為 licensePlate 長度，W 為所有單字長度總和
 * 空間複雜度：O(1)，兩個計數陣列固定 26 格
 * 分類主題：hash-table-counting
 *
 * 解法說明：
 * 先統計車牌中每個字母需要的次數（忽略數字、空格，大小寫視為相同）。
 * 再逐一檢查每個單字：單字中每個字母的可用次數，要能滿足車牌需求。
 * 在所有符合的單字裡，回傳最短的；長度相同則回傳在 words 中最早出現的。
 */
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        // counts[i] = 車牌中字母 ('a' + i) 需要出現的次數
        array<int, 26> counts = {};
        for(char& c : licensePlate)  
            // isalpha 過濾掉數字與空格；c | 32 把大寫轉小寫（只對字母有效，所以要先判斷）
            if(isalpha(c)) counts[(c | 32) - 'a']++;

        string ans;  // 目前最短的符合單字，空字串代表還沒找到

        for(string& word : words) {
            // 剪枝：已有答案且這個單字更長，不可能更短，直接跳過
            // 長度相同的不跳過，但後面用嚴格 < 比較，所以會保留較早出現的那個
            if(!ans.empty() && word.size() > ans.size()) continue;

            // sub_counts[i] = 這個單字中，實際「用來滿足需求」的字母 ('a' + i) 次數
            array<int, 26> sub_counts = {};
            for(char& c : word) {
                int idx = c - 'a';  // words 保證都是小寫
                // 只在車牌需要這個字母、且還沒湊滿需求時才累加，
                // 超出需求的部分不算，這樣最後可以直接用 == 比較是否剛好湊齊
                if(counts[idx] > 0 && sub_counts[idx] < counts[idx]) sub_counts[idx]++;
            }

            // sub_counts 等於 counts 代表每個需求都被滿足
            // 且（還沒答案，或這個單字嚴格更短）才更新，長度相同保留先出現的
            if(sub_counts == counts && (ans.empty() || word.size() < ans.size())) ans = word;
        }
        return ans;
    }
};
