/**
 * 題目：738. Monotone Increasing Digits
 * 難度：中等 (Medium)
 * 分類主題：greedy-digit-construction
 * 描述：給定一個非負整數 n，求小於等於 n、且數字由左到右「單調不
 * 遞減」（每一位都 >= 前一位）的最大整數。
 *
 * 時間複雜度：O(N)，N 是數字位數
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （從右往左掃描，找出第一個「逆序」的地方就往前修正，這是跟 402
 * 相反方向的貪心——402 是從左往右刪、這題是從右往左改）：
 * 1. 從右往左掃描每一位，如果發現 s[i-1] > s[i]（前一位比後一位大，
 *    違反單調不遞減），代表這裡是問題所在：把 s[i-1] 減 1（讓它不再
 *    比後面大），並記錄「從這個位置往後，所有數字都要改成 9」
 *    （markFrom = i）。
 * 2. **為什麼往後都要填 9**：因為前一位被減 1 之後，為了讓整個數字
 *    盡量大，後面能填的都應該填到最大值 9（只要不超過原數字的整數
 *    範圍限制，填 9 一定是最大選擇）。
 * 3. 持續往左掃描，可能會連鎖修正多個位置（例如 332，先在 i=2 發現
 *    3>2，把 s[1] 從 3 減成 2，markFrom=2；接著在 i=1 發現 s[0]=3 >
 *    s[1]=2（減完後的新值），繼續把 s[0] 減成 2，markFrom 更新
 *    成 1；最終結果是 2 9 9 = 299）。
 * 4. 掃描完畢後，把 markFrom 之後的所有位置都填成 '9'，轉回整數
 *    就是答案。
 */
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int markFrom = s.size();

        for (int i = (int)s.size() - 1; i > 0; --i) {
            if (s[i - 1] > s[i]) {
                s[i - 1]--;
                markFrom = i;
            }
        }
        for (int i = markFrom; i < (int)s.size(); ++i) {
            s[i] = '9';
        }
        return stoi(s);
    }
};
