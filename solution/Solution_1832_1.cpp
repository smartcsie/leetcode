/**
 * 題目：1832. Check if the Sentence Is Pangram
 * 難度：簡單 (Easy)
 * 分類主題：bit-manipulation-mask
 * 技巧：accumulate, bitmask
 * 描述：給定一個句子（保證只包含小寫英文字母），判斷它是不是「全字母
 * 句」——也就是 a 到 z 這 26 個字母是否每一個都至少出現過一次。
 *
 * 時間複雜度：O(N)，N 是句子長度
 * 空間複雜度：O(1)（bitmask 固定只需要 26 個 bit）
 *
 * 解法思路：
 * （Bitmask，用一個整數的 26 個 bit 分別代表 a~z 有沒有出現過）：
 * 1. `string& s = sentence` 只是取一個參考別名，方便後面打字簡短，
 *    不影響邏輯（也可以直接用 `sentence`，這行純粹是命名習慣）。
 * 2. 用 `accumulate` 把整個字串摺疊成一個 int 遮罩，初始值 0：對每個
 *    字元 `c`，把 `mask` 的第 `c - 'a'` 個 bit 設成 1（代表這個字母
 *    出現過）。`|=` 的特性讓同一個字母出現幾次都只會設定同一個 bit，
 *    天生去重，不用擔心重複計數。
 * 3. 掃完整個句子後，`ans` 這個 26-bit 遮罩裡，哪些 bit 是 1，就代表
 *    哪些字母出現過。
 * 4. **判斷全字母句的關鍵**：如果 26 個字母都出現過，`ans` 應該剛好
 *    是「26 個 bit 全部是 1」的狀態。`(1 << 26) - 1` 這個算式會產生
 *    剛好 26 個 1 的二進位數字（`1 << 26` 是第 27 個 bit 是 1、其餘
 *    是 0，再減 1 會把這個 1 借位往下傳，變成前面 26 個 bit 全部
 *    翻成 1）。直接比較 `ans` 是否等於這個值，就能一次判斷「是不是
 *    每個字母都出現過」，不用逐一檢查 26 個 bit。
 */
class Solution {
public:
    bool checkIfPangram(string sentence) {
        string& s = sentence;
        int ans = accumulate(s.begin(), s.end(), 0,[](int mask, char c) {
            mask |= 1 << (c - 'a');
            return mask;
        });
        return ans == (1 << 26) - 1;
    }
};