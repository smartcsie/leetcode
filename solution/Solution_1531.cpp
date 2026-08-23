/**
 * 題目：1531. String Compression II
 * 難度：困難 (Hard)
 * 分類主題：greedy-optimal-partitioning
 * 描述：給定字串 s 和整數 k，最多可以刪除 k 個字元，求刪除後對剩下
 * 的字串做「行程長度編碼」（RLE，相同字元連續出現 count 次寫成
 * 字元+count），能得到的最短編碼長度。
 *
 * 時間複雜度：O(N² * K)
 * 空間複雜度：O(N * K)
 *
 * 解法思路：
 * （這題雖然清單分類在 Optimal Partitioning，但實際是記憶化搜尋 /
 * 區間型 DP，不是單純的貪心切割——先列出正確解法讓你先收進去）：
 * 1. dp(i, k) 代表「處理 s[i:] 這段、還能刪 k 個字元」時，壓縮後
 *    的最短長度。
 * 2. 每個位置有兩種選擇：
 *    - **刪掉 s[i]**：花掉一次刪除額度，變成 dp(i+1, k-1)。
 *    - **保留 s[i]，並讓它延伸成一段連續相同字元的區塊**：往右掃描
 *      j，統計「跟 s[i] 相同的字元數」same、以及「需要刪掉的不同
 *      字元數」diffDeleted；只要 diffDeleted 沒超過 k 額度，就可以
 *      把 [i, j] 這段壓成一個區塊（長度是 getLen(same)，例如 same=1
 *      壓成 1 個字元、same 是兩位數壓成 2+1=3 個字元），加上剩下
 *      部分的最佳解 dp(j+1, k-diffDeleted)，取所有可能 j 裡最小值。
 * 3. getLen(count) 依照 RLE 規則計算數字部分需要幾位數：count=1 時
 *    不寫數字（長度1）；1<count<10 長度2；10~99 長度3；100+ 長度4。
 * 4. 用記憶化避免重複計算相同的 (i, k) 狀態。
 */
class Solution {
    map<pair<int,int>,int> memo;
    string s;
    int n;

    int getLen(int count) {
        if (count == 1) return 1;
        if (count < 10) return 2;
        if (count < 100) return 3;
        return 4;
    }

    int dp(int i, int k) {
        if (k < 0) return INT_MAX / 2;
        if (i == n) return 0;
        auto key = make_pair(i, k);
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;

        int res = dp(i + 1, k - 1);
        int same = 0, diffDeleted = 0;
        for (int j = i; j < n && diffDeleted <= k; ++j) {
            if (s[j] == s[i]) same++;
            else diffDeleted++;
            res = min(res, getLen(same) + dp(j + 1, k - diffDeleted));
        }
        return memo[key] = res;
    }

public:
    int getLengthOfOptimalCompression(string s_, int k_) {
        s = s_;
        n = s.size();
        return dp(0, k_);
    }
};
