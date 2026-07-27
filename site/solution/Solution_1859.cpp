/**
 * 題目：1859. Sorting the Sentence (將句子排序)
 * 難度：簡單 (Easy)
 * 描述：將包含數字結尾的單字句子，依據數字順序還原句子。
 * * 時間複雜度：O(N) - N 為字串長度，只需遍歷一次。
 * 空間複雜度：O(N) - 用於儲存分割後的單字。
 * * 優化思路：
 * 利用單字結尾數字 (1-9) 作為陣列索引，直接將單字放入對應的 bucket 中，
 * 避免了使用 sort() 進行比較排序的 O(N log N) 成本。
 */

class Solution {
public:
    string sortSentence(string s) {
        // 題目限制單字數最多 9 個，建立大小為 10 的陣列作為桶子
        vector<string> buckets(10);
        stringstream ss(s);
        string word;
        int word_count = 0;
        
        while (ss >> word) {
            // 取得最後一個字元並轉為整數索引
            int pos = word.back() - '0';
            // 移除末尾數字
            word.pop_back();
            // 放入對應位置
            buckets[pos] = word;
            word_count++;
        }
        
        string res = "";
        for (int i = 1; i <= word_count; ++i) {
            res += buckets[i];
            // 若不是最後一個單字，則補上空格
            if (i < word_count) {
                res += " ";
            }
        }
        
        return res;
    }
};
