/**
 * 題目：2053. Kth Distinct String in an Array (陣列中第 K 個不同的字串)
 * 難度：簡單 (Easy)
 * 描述：找出陣列中第 k 個出現次數恰好為 1 的字串。
 * * 時間複雜度：O(N)，兩次遍歷陣列 (一次計數，一次篩選)。
 * 空間複雜度：O(N)，雜湊表儲存所有字串的頻率。
 * * 優化思路：
 * 1. 記憶體預留：對於較大的陣列，提前預留雜湊表空間能減少重新雜湊 (Rehash) 的開銷。
 * 2. 邏輯簡化：保留原始的兩次遍歷邏輯，這是此問題在時間複雜度上的最佳解。
 */

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> counts;
        for(const string& s : arr) counts[s]++;
        for(const string& s : arr) {
            if(counts[s] == 1 && --k == 0) return s;
        }
        return "";
    }
};
