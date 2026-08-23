/**
 * 題目：1405. Longest Happy String
 * 難度：中等 (Medium)
 * 分類主題：greedy-exchange-argument
 * 描述：給定 a、b、c 三個數字，分別代表能用的 'a'、'b'、'c' 字元
 * 個數，組成一個「快樂字串」（不能有 3 個以上連續相同字元），求能
 * 組成的最長快樂字串（多解取任一組）。
 *
 * 時間複雜度：O((a+b+c) log 3)（每輪排序 3 個元素，可視為常數）
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （跟 984. String Without 3 Identical Consecutive Letters 同一招，
 * 只是候選從 2 個變成 3 個：984 只有兩種字元，被擋住時「別無選擇」
 * 只能放另一個；這裡有三種，被擋住時還要再比一次「剩下的裡誰最多」，
 * 所以改用排序取代 984 的 if/else 直接比較）：
 * 1. 每一輪，把 a、b、c 三個候選連同剩餘數量打包，依數量由多到少
 *    排序（跟 984 比較兩個數字大小的精神一樣，只是這裡有 3 個要比）。
 * 2. 依排序後的順序檢查每個候選：數量已經歸零的跳過；如果放這個
 *    字元會讓結果字串「最後兩個字元」加上它變成三連續，也跳過（跟
 *    984 判斷「會不會湊成三連續」的邏輯完全相同）；第一個「數量夠、
 *    又不會湊成三連續」的候選，就是這一輪要放的字元。
 * 3. 放完一個字元後，重新回到步驟 1 排序（因為剩餘數量變了，排序
 *    結果可能不同），直到某一輪「三個候選都放不了」為止結束——這種
 *    情況只會發生在「唯一還有剩餘的字元，剛好是最後兩個字元」時
 *    （例如 a=7,b=1,c=0，最後剩下的 2 個 a 沒辦法再放，因為前面已經
 *    連續兩個 a 了），這也是 1405 跟 984 最大的不同：984 保證一定能
 *    把 A、B 全部用完，1405 不保證，可能會提前結束、留下用不到的
 *    字母。
 * 4. 因為每輪都要重新排序，這版本沒有像 heap 版那樣把「已放回的候選」
 *    延續到下一輪的機制，而是每輪都重新從頭排序全部三個候選，邏輯
 *    上更直白、更貼近 984 的思路，但常數因子略高於 heap 版（heap
 *    版每次操作是 O(log 3)，這版每輪排序是 O(3 log 3)，數量級一樣，
 *    差異可忽略）。
 */
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;
        while (true) {
            vector<pair<int,char>> counts = {{a,'a'}, {b,'b'}, {c,'c'}};
            sort(counts.begin(), counts.end(), greater<>());

            bool placed = false;
            for (auto& [count, ch] : counts) {
                if (count <= 0) continue;
                int len = res.size();
                bool blocked = len >= 2 && res[len-1] == ch && res[len-2] == ch;
                if (!blocked) {
                    res += ch;
                    if (ch == 'a') a--;
                    else if (ch == 'b') b--;
                    else c--;
                    placed = true;
                    break;
                }
            }
            if (!placed) break;
        }
        return res;
    }
};