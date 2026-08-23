/**
 * 題目：767. Reorganize String
 * 難度：中等 (Medium)
 * 描述：給定一個字串 s，重新排列讓「相鄰的兩個字元都不相同」，回傳
 * 任一組合法解；如果不存在合法排列，回傳空字串。
 *
 * 時間複雜度：O(N log K)，K 是不同字元種類數（最多 26）
 * 空間複雜度：O(K)
 *
 * 解法思路：
 * （Huffman-Type Greedy，用 max-heap 每次挑「目前剩最多」的字元放
 * 進結果，這樣才能盡量把出現次數多的字元「分散」開來）：
 * 1. 先判斷可行性：如果某個字元出現次數超過 (n+1)/2（n 是字串長度），
 *    代表這個字元多到怎麼排都會有兩個相鄰，直接回傳空字串。
 * 2. 用 max-heap 存「(出現次數, 字元)」，每次取出出現次數最多的兩個
 *    字元 c1、c2，依序接在結果字串後面（c1、c2 一定不同，因為是不同
 *    字元各自的計數），扣掉各自的計數（-1），如果扣完還大於 0 就
 *    放回 heap。
 * 3. **為什麼一次要拿兩個而不是一個**：只拿一個字元放進結果、放回
 *    heap 的話，heap 頂端很可能又是同一個字元（因為它出現次數還是
 *    最多），會導致相鄰重複。一次拿兩個不同的字元交替放，才能保證
 *    這一輪放進去的兩個字元彼此不相鄰、也跟上一輪最後放的字元不同
 *    （因為上一輪最後放的字元這一輪計數變小，不會再排在最前面）。
 * 4. 最後如果 heap 剩一個字元（代表原字串長度是奇數），直接接在
 *    結果最後面——這時候它的計數保證只剩 1（前面已經檢查過可行性），
 *    不會跟前一個字元相同。
 */
class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        int n = s.size();
        int maxFreq = *max_element(freq.begin(), freq.end());
        if (maxFreq > (n + 1) / 2) return "";

        priority_queue<pair<int,char>> maxHeap;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) maxHeap.push({freq[i], (char)('a' + i)});
        }

        string result;
        while (maxHeap.size() >= 2) {
            auto [f1, c1] = maxHeap.top(); maxHeap.pop();
            auto [f2, c2] = maxHeap.top(); maxHeap.pop();
            result += c1;
            result += c2;
            if (f1 - 1 > 0) maxHeap.push({f1 - 1, c1});
            if (f2 - 1 > 0) maxHeap.push({f2 - 1, c2});
        }
        if (!maxHeap.empty()) {
            auto [f, c] = maxHeap.top();
            result += c;
        }
        return result;
    }
};
