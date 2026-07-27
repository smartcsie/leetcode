/**
 * 題目：1544. Make The String Great (整理字串)
 * 難度：簡單 (Easy)
 * 描述：消除字串中所有相鄰且大小寫互補（如 'aA' 或 'Aa'）的字元對，直到無法再消除為止。
 * * 時間複雜度：O(N) - 每個字元僅進出堆疊一次。
 * 空間複雜度：O(N) - 堆疊最多儲存所有字元。
 * * 優化思路：
 * 1. 堆疊模擬：直接利用 string 本身作為堆疊，避免額外的資料結構開銷。
 * 2. 條件判斷：利用 ASCII 碼差異（'a' - 'A' = 32）進行高效判斷。
 */

class Solution {
public:
    string makeGood(string s) {
        string res;
        for(const char& c : s) {
            if(!res.empty() && abs(c - res.back()) == 32) {
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        return res;
    }
};
