// 題目：66. Plus One
// 難度：Easy
// 時間複雜度：O(n)
// 空間複雜度：O(1)（原地修改；全部是 9 時 insert 可能重新配置一次）
// 分類主題：array / math
// 技巧：從最低位往高位處理進位，遇到非 9 就能提前結束

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // 從最低位（陣列尾端）開始加 1，往高位處理進位
        for(int i = digits.size() - 1; i >= 0; i--) {
            if(digits[i] == 9) {
                // 9 + 1 = 10：這一位變 0，向前一位進位，繼續迴圈
                digits[i] = 0;
            } else {
                // 不是 9：加 1 後不會再進位，直接完成並回傳
                // 例：[1,2,9] -> 9 變 0，再處理 2：2 + 1 = 3 -> [1,3,0]
                digits[i]++;
                return digits;
            }
        }

        // 能走到這裡代表每一位都是 9（如 [9,9,9]），迴圈已把它們全部變成 0
        // 最高位還有進位，要在最前面補一個 1：[0,0,0] -> [1,0,0,0]
        // insert 在開頭需要搬動所有元素，是 O(n)，但只會發生一次
        digits.insert(digits.begin(), 1);
        return digits;
    }
};