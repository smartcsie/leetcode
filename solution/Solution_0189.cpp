/**
 * 解題思路：雙指標法 (Two Pointers)
 * 1. 使用兩個指標：left 指向字串開頭，right 指向字串結尾。
 * 2. 當 left < right 時，交換兩個指標所指向的字元。
 * 3. 交換後，將 left 向右移動，right 向左移動，直到兩者相遇或交錯。
 * 
 * 這種方法不需要額外的空間來儲存字串，直接在原有的 vector 上進行操作。
 * 
 * Time Complexity: O(n) - 遍歷半個陣列，進行 n/2 次交換。
 * Space Complexity: O(1) - 僅使用兩個整數變數作為指標，原地修改。
 */

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size() - 1;
        while( i <= j) {
            swap(s[i++], s[j--]);
        }
    }
};
