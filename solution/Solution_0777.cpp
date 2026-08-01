/**
 * 題目：777. Swap Adjacent in LR String (在 LR 字串中交換相鄰字元)
 * 難度：中等 (Medium)
 * 描述：字串只由 'L'、'R'、'X' 組成，可以透過兩種操作互相轉換："XL" 可換成 "LX"
 *       （L 往左移），"RX" 可換成 "XR"（R 往右移）。判斷 start 是否能透過任意次數
 *       這樣的操作，變成 result。
 *
 * 時間複雜度：O(N) - 雙指標各自對兩個字串線性掃描一次。
 * 空間複雜度：O(1) - 只使用常數個變數（i, j），不需額外配置記憶體。
 *
 * 解法思路：
 * 1. 關鍵觀察：L 只能左移、R 只能右移，且彼此相對順序不能改變 (Key Invariant)：
 *    - 因為交換規則的限制，'L' 只能往左移動、'R' 只能往右移動，
 *      而所有 L 與 R 之間的相對先後順序永遠不會改變（不能互相跨越）。
 * 2. 用雙指標同步跳過兩字串中的 'X' (Skip X with Two Pointers)：
 *    - i、j 分別在 start、result 中前進，各自跳過連續的 'X'，
 *      找到下一個「非 X 字元」（也就是 L 或 R）進行比對。
 * 3. 驗證字元種類是否相同、且移動方向合法：
 *    - 若兩邊當前找到的非 X 字元不同（例如一個是 L、一個是 R），代表順序被打亂，直接回傳 false。
 *    - 若是 'L'，則要求原本位置 i 必須大於等於目標位置 j（i < j 代表 L 需要往右移，不合法）。
 *    - 若是 'R'，則要求原本位置 i 必須小於等於目標位置 j（i > j 代表 R 需要往左移，不合法）。
 * 4. 收尾檢查：確保兩邊剩餘的字元都只是多餘的 'X' (Trailing X Check)：
 *    - 若其中一個字串先走完，另一個字串剩下的部分必須全部是 'X'，
 *      否則代表兩邊的 L/R 數量不一致，無法轉換成功。
 */
class Solution {
public:
    bool canTransform(string start, string result) {
        int n = start.size(), i = 0, j = 0;
        while (i < n && j < n) {
            while (i < n && start[i] == 'X') ++i;
            while (j < n && result[j] == 'X') ++j;
            if (start[i] != result[j]) return false;
            if ((start[i] == 'L' && i < j) || (start[i] == 'R' && i > j)) return false;
            ++i; ++j;
        }
        while (i < n) {
            if (start[i] != 'X') return false;
            ++i;
        }
        while (j < n) {
            if (result[j] != 'X') return false;
            ++j;
        }
        return true;
    }
};
