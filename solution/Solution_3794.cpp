/**
 * 題目：Reverse Prefix of Word (反轉單字前綴)
 * 難度：簡單 (Easy)
 * 描述：給定一個字串 s 和一個字元 ch，反轉從字串開頭到 ch 第一次出現位置之間的字串。
 * * 時間複雜度：O(N) - 字串掃描一次。
 * 空間複雜度：O(1) - 原地修改。
 * * 優化思路：
 * 1. 使用 std::reverse：STL 提供的反轉函數是最佳化過的，直接使用可以降低手寫指標錯誤風險。
 */

class Solution {
public:
    string reversePrefix(string s, char ch) {
        // 1. 尋找目標字元 ch 的位置
        size_t pos = s.find(ch);
        
        // 2. 如果找到了，反轉 [0, pos] 的區間
        if (pos != string::npos) {
            // reverse 區間為左閉右開 [first, last)
            reverse(s.begin(), s.begin() + pos + 1);
        }
        
        return s;
    }
};


/*
class Solution {
public:
    string reversePrefix(string s, int k) {
        int left = 0;
        int right = k - 1;
        while(left < right) {
            swap(s[left], s[right]);
            if((left < right)) left++;
            if((left < right)) right--;
        }
        return s;
    }
};
*/
