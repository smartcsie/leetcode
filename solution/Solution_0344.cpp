/**
 * 題目：344. Reverse String
 * 難度：簡單 (Easy)
 * 描述：原地反轉字元陣列。
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)

 */
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i =0; i< n/2; i++) {
            swap(s[i],s[n-1-i]);
        }
    }
};