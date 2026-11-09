/**
 * 題目：1016. Binary String With Substrings Representing 1 To N
 * 難度：Medium
 * 描述：給定二進位字串 s 與正整數 n。若 1 到 n 的每個整數的二進位表示
 *       （不含前導 0）都是 s 的子字串，回傳 true，否則回傳 false。
 *
 * 分類主題：string
 * 技巧：只檢查 (n/2, n] 這一半, 長度上界提早剪枝 n > 2 * s.size(), std::format("{:b}") 轉二進位字串
 *
 * 時間複雜度：O(L^2 log L) 的量級，L 為 s 的長度
 *   剪枝後 n <= 2L，迴圈約 n/2 <= L 次，每次 find 最壞約 O(L * log n)
 * 空間複雜度：O(log n)，只存一個二進位字串
 *
 * 解法思路：剪枝 + 只檢查後一半
 * 1. 只需檢查 (n/2, n]：
 *    任何整數 x 的二進位，去掉最後一位就是 x / 2 的二進位，
 *    所以 x 是 s 的子字串，則 x / 2 也一定是（它是 x 的前綴）。
 *    因此 (n/2, n] 都在 s 裡，就代表 [1, n/2] 也都在，不用再檢查。
 * 2. 長度剪枝：n > 2 * s.size() 直接回傳 false。
 *    (n/2, n] 共有 ceil(n/2) 個不同的數，每個都是 s 的一段子字串。
 *    這些數的二進位表示彼此不會互為前綴
 *    （若 y 是 x 的前綴，則 y = x / 2 <= n / 2，不在檢查範圍內），
 *    所以它們必須從 s 的不同起點開始，至少需要 ceil(n/2) 個起點，
 *    即 s.size() >= ceil(n/2)。反過來 n > 2L 時一定不可能全部包含。
 * 3. 剪枝之後 n <= 2L，題目 L <= 1000，所以迴圈最多約 1000 次。
 * 4. 由大到小檢查，較大的數位元較長、較難在 s 中出現，能更早失敗。
 * 5. std::format 需要 C++20 與 <format>。
 */

class Solution {
public:
    bool queryString(string s, int n) {
        if (n > 2 * (int) s.size()) {
            return false;
        }
        for (int num = n; num > n / 2; --num) {
            string b_str = std::format("{:b}", num);
            if (s.find(b_str) == string::npos) {
                return false;
            }
        }
        return true;
    }
};