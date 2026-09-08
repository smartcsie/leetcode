/**
 * 題目：2864. Maximum Odd Binary Number
 * 難度：簡單 (Easy)
 * 描述：重排二進位字串，使其為最大的奇數二進位數。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （確保最低位為 1，其餘 1 移到最高位）：
 * 先將一個 1 移到最後一位，再將其餘的 1 都移到前面。
 */
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        if(s.back() == '0') {
            int right = s.size() -1;
            while(right >=0 && s[right] == '0') right--;
            if(right >= 0) swap(s[right], s[s.size() -1]);
        }
        for(int i = 0, j = 0; i < s.size() -1 && j < s.size() -1 ; i++) {
                if(s[i] == '1') swap(s[i],s[j++]);
        }
        return s;
    }
};