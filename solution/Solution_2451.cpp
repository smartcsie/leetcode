/**
 * 題目：2451. Odd One Out
 * 難度：Easy
 * 時間複雜度：O(N * L)，N 為字串數量，L 為每個字串長度（建立差值向量跟放進 map 都要掃過字串）
 * 空間複雜度：O(N * L)，map 裡每個 key 是長度 L-1 的差值向量
 * 分類主題：hash-table-grouping
 *
 * 思路：
 * 每個字串本質上是由「相鄰字元的差值序列」決定它的形狀，
 * 題目保證除了一個字串外，其他字串的差值序列都完全相同，
 * 所以把每個字串轉成差值向量當作 key，用 map 分組，
 * 最後找出哪一組只有 1 個字串，那個字串就是答案。
 */
class Solution {
public: 
    string oddString(vector<string>& words) {
        // key：字串的「相鄰字元差值」序列；value：擁有這個差值序列的所有原始字串
        map<vector<int>, vector<string>> mp;

        for(const string& word : words) {
            // 把字串轉成差值向量，例如 "abc" -> [1, 1]（b-a=1, c-b=1）
            vector<int> diff(word.size() - 1);
            for(int i = 1; i < word.size(); i++) {
                diff[i - 1] = word[i] - word[i - 1];
            }
            mp[diff].push_back(word);
        }

        // 差值序列相同的字串會被分在同一組，唯一一個「組員只有 1 個」的
        // 那一組，就是跟別人形狀不一樣的那個落單字串
        for(const auto& [_, strs] : mp) {
            if(strs.size() == 1) return strs[0];
        }

        return ""; // 題目保證一定找得到答案，這行理論上不會被執行
    }
};
