/**
 * 題目：2729. Check if The Number is Fascinating (檢查數字是否是迷人數字)
 * 難度：簡單 (Easy)
 * 描述：給定一個三位數整數 n，將 n 與 2n 及 3n 拼接成一個新數字，
 *       若這個新數字剛好包含 1 到 9 每個數字各恰好一次（不含 0），則稱 n 為迷人數字。
 *
 * 時間複雜度：O(logN) - 對 n、2n、3n 各自進行一次位數拆解，總位數固定為常數（三位數規模）。
 * 空間複雜度：O(1) - 使用固定大小 10 的 bitset，不隨輸入規模成長。
 *
 * 解法思路：
 * 1. 逐一計算 n、2n、3n 並拆解數字 (Digit Decomposition)：
 *    - 依序對 i = 1, 2, 3 計算 i * n，並從個位數開始逐位拆解每個數字。
 * 2. 利用 bitset 記錄數字出現狀況 (Bitset Tracking)：
 *    - 用長度為 10 的 bitset 記錄哪些數字（1~9）已經出現過。
 * 3. 提前失敗的條件判斷：
 *    - 若拆解出的某個位數為 0，代表不符合「只能包含 1~9」的要求，直接回傳 false。
 *    - 若某個數字已經在 bitset 中被標記過（代表重複出現），也直接回傳 false（違反「恰好一次」的要求）。
 * 4. 最終驗證：
 *    - 走訪完 n、2n、3n 的所有位數後，檢查 bitset 中被設定的數字數量是否恰好為 9，
 *      代表 1~9 每個數字都各出現了一次。
 */
class Solution {
public:
    bool isFascinating(int n) {
        bitset<10> bits;
        bits.set(0);
        for(int i = 1; i <= 3; i++) {
            int num = n * i;
            while(num > 0) {
                int digit = num % 10;
                if(bits.test(digit)) return false;
                bits.set(digit);
                num /= 10;
            }
        }
        return bits.count() == 10;
    }
};
