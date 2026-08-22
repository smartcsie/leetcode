/**
 * 題目：1467. Probability of a Two Boxes Having The Same Number of Distinct Balls
 * 難度：困難 (Hard)
 * 描述：給定 k 種顏色的球，balls[i] 是第 i 種顏色的球數，把所有球
 * （總數一定是偶數）隨機均分成兩箱，每箱各 total/2 顆。求「兩箱裡
 * 不同顏色種類數相等」的機率。
 *
 * 時間複雜度：O(∏(balls[i]+1))（枚舉每種顏色的分配方式）
 * 空間複雜度：O(K)（遞迴深度）
 *
 * 解法思路：
 * （這題不是遞推型 DP，而是「組合數學 + DFS 枚舉」，Probability DP
 * 這個分類裡比較特殊的一種形式——用回溯窮舉所有分配方式，加權計數）：
 * 1. 把所有球想像成「可以區分」的個體（同顏色的球雖然看起來一樣，但
 *    當作不同個體處理），這樣「隨機均分成兩箱」就等價於「從 total 個
 *    可區分的球裡，選 total/2 個放進箱子 A」，這是一個組合問題：
 *    分母（denominator）= C(total, total/2)，代表所有可能的分法總數。
 * 2. 分子（numerator）：對每種顏色 i，決定要放 x 顆進箱子 A（剩下
 *    balls[i]-x 顆進箱子 B），這樣的分法數是組合數 C(balls[i], x)
 *    （因為同色球雖然「可區分」，但只關心「選了幾顆」，用組合數表示
 *    有幾種選法）。用 DFS 對每種顏色枚舉 x = 0 到 balls[i]，把各顏色
 *    的組合數「連乘」起來，累積出這整個分配方式的權重（ways）。
 * 3. DFS 到底（處理完所有顏色）之後檢查兩個條件：
 *    a. 箱子 A 的球數總和剛好是 total/2（因為兩箱要一樣多）。
 *    b. 箱子 A 有球的顏色種類數（countA）等於箱子 B 有球的顏色種類數
 *       （countB）——這正是題目要求的「不同顏色種類數相等」。
 *    兩個條件都滿足，才把這個分配方式的權重 ways 累加進 numerator。
 * 4. 答案 = numerator / denominator。
 */
class Solution {
public:
    double getProbability(vector<int>& balls) {
        int k = balls.size();
        int total = accumulate(balls.begin(), balls.end(), 0);
        int half = total / 2;

        vector<double> factorial(50);
        factorial[0] = 1;
        for (int i = 1; i < 50; ++i) factorial[i] = factorial[i - 1] * i;

        double numerator = 0.0;

        function<void(int,int,int,int,double)> dfs =
            [&](int i, int sumA, int countA, int countB, double ways) {
            if (i == k) {
                if (sumA == half && countA == countB) {
                    numerator += ways;
                }
                return;
            }
            for (int x = 0; x <= balls[i]; ++x) {
                int y = balls[i] - x;
                double split = factorial[balls[i]] / (factorial[x] * factorial[y]);
                dfs(i + 1, sumA + x, countA + (x > 0 ? 1 : 0), countB + (y > 0 ? 1 : 0), ways * split);
            }
        };
        dfs(0, 0, 0, 0, 1.0);

        double denominator = factorial[total] / (factorial[half] * factorial[total - half]);
        return numerator / denominator;
    }
};
