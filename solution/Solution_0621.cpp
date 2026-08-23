/**
 * 題目：621. Task Scheduler
 * 難度：中等 (Medium)
 * 描述：給定一組任務 tasks（用字母表示種類）和一個冷卻時間 n，相同
 * 種類的任務之間至少要間隔 n 個單位時間（可以用其他任務或閒置填補），
 * 求完成所有任務所需的最短時間。
 *
 * 時間複雜度：O(N)（N 為任務總數，統計頻率是線性的）
 * 空間複雜度：O(1)（只需要 26 個字母的計數）
 *
 * 解法思路：
 * （數學公式解，不需要真的模擬排程過程——這是這題最容易讓人意外的
 * 地方，看似是排程問題，實際上是「用出現次數最多的任務去決定排程
 * 骨架」的推導題）：
 * 1. 統計每個任務種類出現的次數，找出最大出現次數 maxFreq，以及
 *    「出現次數剛好等於 maxFreq」的任務種類數 maxCount。
 * 2. **核心觀察**：把出現次數最多的那個任務當作骨架，排成
 *    `X _ _ ... X _ _ ... X`（X 出現 maxFreq 次，每個 X 之間有 n 個
 *    空格），這個骨架的長度是 `(maxFreq - 1) * (n + 1) + 1`。如果剛好
 *    有 maxCount 種任務都達到最大出現次數，最後一個 X 的位置可以塞下
 *    這些並列的任務，所以骨架長度變成
 *    `(maxFreq - 1) * (n + 1) + maxCount`。
 * 3. 其他出現次數較少的任務，可以見縫插針地塞進骨架的空格裡，不會讓
 *    整體時間變長（因為它們的次數不會超過空格數）。
 * 4. **但有一種情況這個公式會失真**：如果任務種類非常多、多到光是把
 *    所有任務排一遍（不用等待）就已經比算出來的骨架長度還長，這時候
 *    答案就是任務總數本身（因為每個時間點都排滿任務，完全不需要閒置）。
 *    所以最終答案是 `max(任務總數, 骨架長度)`。
 */
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char t : tasks) freq[t - 'A']++;

        int maxFreq = *max_element(freq.begin(), freq.end());
        int maxCount = count(freq.begin(), freq.end(), maxFreq);

        int frameLength = (maxFreq - 1) * (n + 1) + maxCount;
        return max((int)tasks.size(), frameLength);
    }
};
