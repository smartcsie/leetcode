/**
 * 題目：541. Reverse String II (反轉字串 II)
 * 難度：簡單 (Easy)
 * 描述：每 2k 個字元，反轉前 k 個。若剩餘字元少於 k，則全部反轉；若介於 k 和 2k 之間，只反轉前 k 個。
 * * 時間複雜度：O(N) - 每個字元最多被存取一次。
 * 空間複雜度：O(1) - 原地操作 (若不計 stack 空間)。
 * * 優化思路：
 * 1. 使用 std::reverse：標準庫函數經過編譯器優化，比手寫 swap 循環更簡潔且不容易出錯。
 * 2. 邊界簡化：使用 min 函數處理剩餘字元的極端情況，使代碼更為精簡。
 */

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        // 每次跳 2k 個步長
        for (int i = 0; i < n; i += 2 * k) {
            // 定義需要反轉的區間：[i, min(i + k, n) - 1]
            // std::reverse 的區間是左閉右開 [first, last)
            int end = min(i + k, n);
            reverse(s.begin() + i, s.begin() + end);
        }
        return s;
    }
};



/*
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for(int i = 0;i < n; i += 2*k) {
            int left = i;
            int right = min(i + k - 1, n -1);
            while(right < s.size() && left < right) {
                swap(s[left], s[right]);
                if(left < right) left++;
                if(left < right) right--;
            }
        }
        return s;
    }
};
*/
