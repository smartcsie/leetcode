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
        int shift = 0;
        for (int i = shifts.size() - 1; i >= 0; --i) {
            shift = (shift + shifts[i]) % 26;
            s[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }
        return s;
    }
};
