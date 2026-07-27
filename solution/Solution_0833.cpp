/**
 * 題目：833. Find And Replace in String (字串中的查找與替換)
 * 難度：中等 (Medium)
 * 描述：在字串 s 中執行多個替換操作，若 sources 與 s 對應位置匹配，則替換為 targets。
 * * 時間複雜度：O(N + M*K)，N 為 s 長度，M 為替換操作次數，K 為 source 平均長度。
 * 空間複雜度：O(N) - 儲存結果與映射表。
 * * 優化思路：
 * 1. 映射表：利用 pair 陣列儲存索引與操作映射，避免對長度為 N 的陣列進行遍歷。
 * 2. 效率：透過 substring 匹配後，直接建構 result 字串，保持 O(N) 性能。
 */

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = static_cast<int>(s.size());
        int m = static_cast<int>(indices.size());
        // 使用映射陣列存放：index -> 替換操作編號
        vector<int> opIndex(n, -1);
        for (int i = 0; i < m; ++i) {
            int start = indices[i];
            // 檢查是否匹配
            if (s.compare(start, sources[i].size(), sources[i]) == 0) {
                opIndex[start] = i;
            }
        }
        string res;
        res.reserve(n); // 預分配記憶體，減少動態擴容
        for (int i = 0; i < n; ) {
            if (opIndex[i] != -1) {
                // 若該位置有合法替換
                res += targets[opIndex[i]];
                i += sources[opIndex[i]].size();
            } else {
                // 否則直接加入原字串
                res.push_back(s[i]);
                i++;
            }
        }
        return res;
    }
};
