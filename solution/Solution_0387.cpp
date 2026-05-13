/**
 * 解題思路：兩次遍歷法 (Two-pass Hash Table)
 * 1. 第一次遍歷：統計每個字元出現的次數。
 *    - 由於字元範圍是小寫英文字母，使用 int[26] 陣列作為哈希表，效率最高。
 * 2. 第二次遍歷：按順序檢查字串 s 中的字元。
 *    - 第一個在哈希表中計數為 1 的字元，就是我們要找的「第一個不重複字元」。
 * 3. 如果遍歷完都沒有找到，回傳 -1。
 * 
 * Time Complexity: O(n) - 需要遍歷兩次字串，分別為統計與查找。
 * Space Complexity: O(1) - 使用了固定長度 (26) 的陣列，與輸入字串長度無關。
 */

class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = {0};
        for(char c : s) {
            count[c-'a']++;
        }
        for(int i = 0; i < s.size(); i++) {
            if(count[s[i]-'a'] == 1) return i;
        }
        return -1;
    }
};
