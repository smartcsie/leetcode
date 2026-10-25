/**
 * 題目：2491. Divide Players Into Teams of Equal Skill
 * 難度：Medium
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)，counts 大小固定為 1001
 * 分類主題：hash-table-counting
 *
 * 解法說明：
 * 每隊兩人技能總和必須相同。若共有 teams 隊，總和固定為 totalSum / teams，
 * 所以每隊的目標和 teamSum 可以直接算出來（不能整除就無解）。
 * 接著掃描每個技能值 x，需要的搭檔是 y = teamSum - x：
 *   - 若 y 已經在等待配對 → 組成一隊，累加化學反應值 x * y
 *   - 否則 x 先存起來等待之後的搭檔
 * 最後所有人都要配成功，配對隊數必須剛好等於 teams。
 */
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int teams = n / 2;          // 每隊 2 人（題目保證 n 為偶數）
        long long sum = 0;          // 所有隊伍的化學反應值總和
        // 總和必須能被隊數整除，每隊的和才會是整數且相同
        int totalSum = accumulate(skill.begin(), skill.end(), 0);
        if(totalSum % teams != 0) return -1;
        int teamSum = totalSum / teams;  // 每隊必須達到的技能總和
        // counts[v] = 目前正在等待配對、技能值為 v 的人數（技能值範圍 1~1000）
        array<int, 1001> counts = {};
        int matchs = 0;  // 已成功配成的隊數
        for(const int& x : skill) {
            int y = teamSum - x;  // x 需要的搭檔技能值
            // y 超出合法技能範圍，代表 x 不可能找到搭檔，直接無解
            // （同時避免下面存取 counts[y] 時越界）
            if(y < 1 || y > 1000) return -1;
            if(counts[y] > 0) {
                // 有人在等 y → 與 x 配成一隊，化學反應值為兩者技能值乘積
                sum += static_cast<long long>(x * y);
                counts[y]--;   // 消耗掉一個等待中的 y（x == y 時也是正確的）
                matchs++;
            } else {
                // 暫時找不到搭檔，先記下來等後面的人
                counts[x]++;
            }
        }
        // 若有人始終沒配到對（matchs < teams），代表無法分成合法隊伍
        return (matchs == teams) ? sum : -1;
    }
};