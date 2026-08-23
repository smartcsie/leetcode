/**
 * 題目：846. Hand of Straights
 * 難度：中等 (Medium)
 * 分類主題：greedy-priority-queue
 * 描述：給定一手牌 hand 和分組大小 groupSize，判斷能不能把這些牌分成
 * 若干組，每組恰好 groupSize 張「連續」的牌。
 *
 * 時間複雜度：O(N log N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （跟 1296 是完全相同的解法，只是題目背景換成撲克牌——用 map 排序
 * 後，每次挑「目前最小」的牌當作一組連續牌的起點）：
 * 1. 牌數不是 groupSize 的倍數，直接回傳 false。
 * 2. 用 map 統計每張牌的數量（自動由小到大排序）。
 * 3. 每次看目前最小的牌 start，它一定要當某組的起點；決定用 start
 *    開頭組成幾組（count = 目前 start 的數量），檢查 start 到
 *    start+groupSize-1 這幾張牌是否都夠用，都扣掉 count 張。
 * 4. 全部檢查完沒有失敗，回傳 true。
 */
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        map<int,int> freq;
        for (int x : hand) freq[x]++;

        for (auto it = freq.begin(); it != freq.end(); ) {
            if (it->second == 0) { ++it; continue; }
            int start = it->first;
            int count = it->second;
            for (int v = start; v < start + groupSize; ++v) {
                auto found = freq.find(v);
                if (found == freq.end() || found->second < count) return false;
                found->second -= count;
            }
            ++it;
        }
        return true;
    }
};
