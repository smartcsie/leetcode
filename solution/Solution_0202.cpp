/**
 * 題目：202. Happy Number (快樂數)
 * 難度：簡單 (Easy)
 * 描述：判斷一個數字 n 是不是快樂數。
 * 
 * 演算法思路：
 * 1. 根據題目定義，重複計算位數平方和。
 * 2. 如果結果變為 1，則是快樂數。
 * 3. 如果結果開始「循環重複」，則永遠不會變為 1，不是快樂數。
 * 4. 使用 std::unordered_set 儲存每一次計算出來的 sum，
 *    每次得到新結果時，檢查是否已存在於集合中以判斷是否進入死循環。
 * 
 * 時間複雜度：O(log n) - 數字縮小的速度極快，且循環的次數在整數範圍內非常有限。
 * 空間複雜度：O(log n) - 需要額外的集合來儲存計算過程中出現的數字。
 */

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> repeat_set;

        while(n != 1) {
            int sum = 0;
            while(n) {
                sum += (n%10) * (n%10);
                n /= 10;
            }
            n = sum;
            if(repeat_set.contains(n)) break;
            repeat_set.insert(n);
        }

        return (n == 1);
    }
};
