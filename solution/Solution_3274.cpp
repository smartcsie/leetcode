/**
 * 題目：3274. Check if Two Chessboard Squares Have the Same Color (檢查兩個棋盤格子顏色是否相同)
 * 難度：簡單 (Easy)
 * 描述：給定兩個字串座標 coordinate1、coordinate2（例如 "a1"），
 *       代表標準 8x8 棋盤上的位置，判斷這兩個格子的顏色（黑或白）是否相同。
 *
 * 時間複雜度：O(1) - 只需常數次位元運算，不隨輸入規模變化。
 * 空間複雜度：O(1) - 只使用常數個變數，不需額外配置記憶體。
 *
 * 解法思路：
 * 1. 棋盤顏色的數學規律 (Chessboard Color Pattern)：
 *    - 標準棋盤的顏色規律是：欄（字母）與列（數字）的奇偶性相加後的結果，
 *      決定該格子是黑色還是白色（相加為偶數代表同色系）。
 * 2. 利用位元運算取得奇偶性 (Bitwise Parity Extraction)：
 *    - coordinate[0] 為字母（如 'a'~'h'），coordinate[1] 為數字字元（如 '1'~'8'）。
 *    - 直接對字元本身取最低位元 (& 1)，即可取出其 ASCII 值的奇偶性，
 *      不需要額外轉換成數值（例如 coordinate[0]-'a'），因為奇偶性在字元轉換前後保持一致。
 * 3. 用 XOR 判斷顏色 (Color via XOR)：
 *    - 將欄與列的奇偶性做 XOR：若結果為 0，代表兩者奇偶性相同（同色格）；
 *      若為 1，代表奇偶性不同（異色格）。
 * 4. 比較兩個座標的顏色：
 *    - 分別計算兩個座標各自的顏色值（0 或 1），若相等即代表兩格顏色相同。
 */
class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        return ((coordinate1[0] ^ coordinate1[1] ^ coordinate2[0] ^ coordinate2[1]) & 1) == 0;
    }
};
