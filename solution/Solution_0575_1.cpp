/**
 * 題目：575. Distribute Candies
 * 難度：Easy
 * 描述：Alice 有 n 顆糖（n 為偶數），candyType[i] 是第 i 顆糖的種類。
 *       醫生要求她最多只能吃 n / 2 顆，她想吃到盡可能多的「不同種類」，
 *       回傳她最多能吃到幾種不同的糖。
 *
 * 分類主題：hash-table-uniqueness
 * 技巧：unordered_set 去重, 答案取 min(種類數, n / 2), 用範圍建構式一行建立集合
 *
 * 時間複雜度：O(N)（雜湊表插入的平均複雜度）
 * 空間複雜度：O(K)，K 為不同種類數，最壞為 O(N)
 *
 * 解法思路：集合去重，取較小者
 * 1. 能吃的上限是 n / 2 顆，所以答案不會超過 n / 2。
 * 2. 糖的總種類數也是上限：就算還有名額，也吃不到不存在的種類。
 * 3. 兩個上限都能達到（挑不同種類各吃一顆即可），所以答案為
 *    min(不同種類數, n / 2)。
 * 4. 用 unordered_set 的範圍建構式把所有糖的種類放進去，
 *    重複的種類會自動被去掉，size() 就是不同種類數。
 *    集合以雜湊儲存，不需要在意值域大小或負數。
 */
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        // 範圍建構式：一次放入所有元素，重複的種類自動去重
        unordered_set<int> uniqueSet(candyType.begin(), candyType.end());

        int half = candyType.size() / 2;  // 最多能吃的顆數

        // 答案不能超過種類數，也不能超過可吃的顆數；size() 是 size_t，要轉成 int 才能和 half 一起 min
        return min(static_cast<int>(uniqueSet.size()), half);
    }
};