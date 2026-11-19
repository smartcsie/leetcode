/**
 * 題目：848. Shifting Letters
 * 難度：Medium
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 * 分類主題：array-suffix-sum
 */
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int totalShift = 0;
        for(int i = s.size() - 1; i >= 0 ; i--) {
            totalShift += shifts[i] % 26;
            s[i] = ((s[i] - 'a') + totalShift) % 26 + 'a';
        }
        return s;
    }
};
