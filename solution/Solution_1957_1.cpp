/*
 * 題目：1957. Delete Characters to Make Fancy String
 * 難度：Easy
 * 描述：若字串中沒有任何三個連續相同的字元，稱為 fancy string。給定字串 s，刪除最少的字元使它成為 fancy string，回傳結果（答案唯一）。
 * 分類主題：two-pointers-same
 * 技巧：快慢指標原地覆寫, 與已保留結果的最後兩個字元比較
 * 時間複雜度：O(n)
 * 空間複雜度：O(1)（原地覆寫，不含傳值複製的參數）
 * 解法思路：
 *   1. fast 掃描原字串，slow 表示已保留字元的個數，s[0..slow-1] 就是目前的結果
 *   2. 若 s[fast] 與結果的最後兩個字元都相同，保留它會造成三個連續相同，必須刪除
 *   3. 否則（結果不足兩個字元，或最後兩個字元不全等於 s[fast]）就寫入 s[slow]，slow 加一
 *   4. 判斷要看「已保留的結果」(s[slow - 1]、s[slow - 2])，不能看原字串 s[fast - 1]、s[fast - 2]，因為前面可能已經被覆寫過
 *   5. 最後 resize 成 slow 即為答案
 */
class Solution {
public:
    string makeFancyString(string s) {
        int slow = 0;   // 已保留字元的個數，也是下一個寫入位置
        for(int fast = 0; fast < s.size(); fast++) {
            // 結果長度不足 2，或最後兩個保留字元不全等於 s[fast]，才能保留
            if(slow < 2 || s[fast] != s[slow - 1] || s[fast] != s[slow - 2]) s[slow++] = s[fast];
        }
        s.resize(slow);   // 截掉多餘的尾巴
        return s;
    }
};