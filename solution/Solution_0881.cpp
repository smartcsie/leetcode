/**
 * 題目：881. Boats to Save People
 * 難度：中等 (Medium)
 * 分類主題：greedy-sorting-decision
 * 描述：給定每個人的體重 people，每艘船最多載兩人、總重量不能超過
 * limit，求最少需要幾艘船才能載完所有人。
 *
 * 時間複雜度：O(N log N)
 * 空間複雜度：O(1)（不含排序）
 *
 * 解法思路：
 * （Sorting + 雙指標貪心，「排序後從兩端夾」是這個 pattern 裡另一種
 * 常見形狀，跟 406 的「排序後決定插入位置」是不同的排序應用方式）：
 * 1. 把體重由小到大排序。
 * 2. 用雙指標 i（最輕的人）、j（最重的人）從兩端往中間夾：
 *    - 如果最輕的人 + 最重的人 <= limit，代表這兩人可以共乘一艘船，
 *      i 前進（最輕的人上船了）。
 *    - 不管上面條件成不成立，j 一定要前進（最重的人這一輪一定要上
 *      船——不是自己坐一艘、就是跟最輕的人共乘），船數 +1。
 * 3. 貪心的正確性：每艘船盡量載两人比只載一人划算（用最少船數的
 *    目標下，能湊一對就湊一對）；而「最重的人 + 目前最輕的人」是
 *    最有機會湊成功的組合——如果連最輕的都湊不進去，那這個最重的人
 *    只能自己坐一艘，跟其他更重的人配對更不可能成功。
 * 4. 迴圈直到 i > j 為止，boats 就是答案。
 */
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        int boats = 0;
        while (i <= j) {
            if (people[i] + people[j] <= limit) {
                i++;
            }
            j--;
            boats++;
        }
        return boats;
    }
};
