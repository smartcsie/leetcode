/**
 * 題目：1668. Maximum Repeating Substring (最大重複子字串)
 * 難度：簡單 (Easy)
 * 描述：找出 word 在 sequence 中連續重複出現的最大次數。
 * * 時間複雜度：O(N * M^2)，其中 N 為 sequence 長度，M 為 word 長度。
 * 空間複雜度：O(M)，用於儲存正在構建的重複子字串。
 * * 優化思路：
 * 1. 記憶體預留：預先為 substr 保留足夠空間，減少記憶體重分配。
 * 2. 邊界條件：題目限制 word 長度 >= 1，程式碼邏輯已涵蓋該情況。
 */

#include <string>

class Solution {
public:
    int maxRepeating(std::string sequence, std::string word) {
        int count = 0;
        std::string current = word;
        
        // 預先為可能的最長重複字串保留空間，避免迴圈內頻繁配置
        current.reserve(sequence.length());
        
        // 當 current 在 sequence 中存在時，繼續嘗試增加下一個 word
        while (sequence.find(current) != std::string::npos) {
            count++;
            current += word; // 直接拼接
        }
        
        return count;
    }
};
