/**
 * 題目：2490. Circular Sentence (環形句)
 * 難度：簡單 (Easy)
 * 描述：檢查句子是否為環形：相鄰詞的銜接處字元相等，且句首與句尾字元相等。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    bool isCircularSentence(string sentence) {
        string& s = sentence;
        if(s.front() != s.back()) return false;
        for(int i = 1; i < s.size() - 1; i++) {
            if(s[i] == ' ' && (s[i - 1] | 32) != (s[i + 1] | 32)) return false;
        }
        return true;
    }
};
