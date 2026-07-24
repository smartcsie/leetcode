/**
 * 題目：1812. Determine Color of a Chessboard Square
 * 描述：給你一個座標 coordinates，由一個小寫英文字母（表示列 a-h）
 *       和一個數字（表示行 1-8）組成。如果該格子是白色，返回 true；
 *       如果是黑色，返回 false。
 * 
 * 解法思路：
 * 1. 西洋棋盤的黑白規律：
 *    - 以左下角 "a1" 為例，'a' 的 ASCII 是 97（奇數），1 是字元 '1'（ASCII 49，奇數）。
 *    - 奇數 + 奇數 = 偶數（在此題中代表黑色）。
 *    - 若字母和數字的 ASCII 相加是奇數（例如奇數 + 偶數，或偶數 + 奇數），則代表白色。
 * 2. 透過 `(coordinates[0] + coordinates[1]) & 1`：
 *    - 直接將兩個字元的 ASCII 數值相加，並用位元運算 `& 1` 檢查最低位（是否為奇數）。
 *    - 若為奇數則運算結果為 1（即 true，代表白色）；若為偶數則為 0（即 false，代表黑色）。
 */

class Solution {
public:
    bool squareIsWhite(std::string coordinates) {
        // 利用字元 ASCII 相加的奇偶性來判斷顏色
        return (coordinates[0] + coordinates[1]) & 1;
    }
