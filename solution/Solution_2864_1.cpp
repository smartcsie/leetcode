// 題目：2864. Maximum Odd Binary Number
// 難度：Easy
// 時間複雜度：O(n)
// 空間複雜度：O(1)（原地交換，操作的是傳進來的副本）
// 分類主題：string / two-pointers / greedy
// 技巧：快慢指標（把 '1' 搬到前面，類似 partition）+ 最後一個 '1' 換到結尾

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();

        // slow：下一個 '1' 要放的位置；[0, slow) 都是已經搬好的 '1'
        int slow = 0;
        for(int fast = 0; fast < n; fast++) {
            // fast 找到 '1' 就和 slow 位置交換，再讓 slow 往後一格
            // 交換後 s[slow] 一定是 '1'，被換走的字元（'0' 或同一格）落在 fast 位置
            if(s[fast] == '1') swap(s[slow++], s[fast]);
        }
        // 此時字串變成「所有 1 在前、所有 0 在後」，例如 "0101" -> "1100"
        // 這是不考慮奇數限制下的最大值

        // 奇數的二進位結尾必須是 1：
        // 把最後一個 '1'（位置 slow - 1）換到字串結尾，其餘的 1 仍然盡量靠左，數值最大
        // 題目保證至少有一個 '1'，所以 slow >= 1，不會越界；
        // 如果全部都是 '1'，slow - 1 == n - 1，等於自己換自己，沒有影響
        swap(s[slow - 1], s[n - 1]);
        return s;
    }
};