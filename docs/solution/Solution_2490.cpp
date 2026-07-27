/**
 * 題目：2490. Circular Sentence (環形句)
 * 難度：簡單 (Easy)
 * 描述：檢查句子是否為環形：相鄰詞的銜接處字元相等，且句首與句尾字元相等。
 * * 時間複雜度：O(N) - 遍歷一次字串。
 * 空間複雜度：O(1) - 僅使用常數空間。
 */

class Solution {
public:
    bool isCircularSentence(string sentence) {
        if(sentence.front() != sentence.back()) return false;
        for(int i = 0; i < sentence.size(); i++) {
            if(sentence[i] == ' ' && sentence[i-1] != sentence[i+1]) return false;
        }
        return true;
    }
};
