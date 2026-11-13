// 題目：326. Power of Three
// 難度：Easy
// 時間複雜度：O(1)
// 空間複雜度：O(1)
// 分類主題：math
// 技巧：對數判斷（log₃(n) 是整數 ⇔ n 是 3 的冪）

class Solution {
public:
    bool isPowerOfThree(int n) {
        // 3 的冪一定是正數；0 與負數的 log 無意義，先排除
        if(n <= 0) return false;

        // 換底公式：log₃(n) = log10(n) / log10(3)
        // 若 n = 3^k，則 log₃(n) = k，是整數
        // fmod(x, 1) 取小數部分（C++ 的 % 不能用在 double），
        // 小數部分為 0 表示 log₃(n) 是整數，即 n 是 3 的冪
        //
        // 這裡要用 log10 而不是 log（自然對數）：
        // log(243) / log(3) 會算出 4.999999999999999，小數部分不為 0 而誤判；
        // log10 在 int 範圍內剛好不會出這個誤差
        return fmod(log10(n) / log10(3), 1) == 0;
    }
};