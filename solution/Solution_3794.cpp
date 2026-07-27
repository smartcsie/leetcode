/**
 * 題目：3794. Reverse String Prefix (字串前綴反轉)
 * 難度：簡單 (Easy)
 * 描述：將字串 s 的前 k 個字元進行反轉並返回結果。
 * * 時間複雜度：O(k) - 僅處理前 k 個字元，整體視為 O(N)。
 * 空間複雜度：O(1) - 原地操作 (若不計字串本身)。
 * * 優化思路：
 * 1. 使用 std::reverse：STL 函式庫已針對不同長度優化，且語意明確，能大幅減少指標偏移與判斷錯誤的機率。
 */

class Solution {
public:
    string reversePrefix(string s, int k) {
        if(s.size() <= 1) return s;
        reverse(s.begin(), s.begin() + k);
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
