/**
 * 題目：462. Minimum Moves to Equal Array Elements II
 * 難度：中等 (Medium)
 * 分類主題：greedy-parity-contribution
 * 描述：給定一個整數陣列 nums，每次操作可以把任一元素 +1 或 -1，求
 * 讓所有元素都相等所需的最少操作次數。
 *
 * 時間複雜度：O(N log N)
 * 空間複雜度：O(1)（不含排序）
 *
 * 解法思路：
 * （這題是這個分類裡最直接體現「排序後根據貢獻挑選目標」的例子：
 * 用經典數學定理，中位數是讓絕對距離總和最小的目標值）：
 * 1. 把陣列排序，取中位數（排序後正中間的元素）當作所有元素要移動
 *    過去的目標值。
 * 2. **為什麼是中位數而不是平均值**：這題每次操作的成本是「距離的
 *    絕對值」（+1/-1 各算一次），不是平方距離。對絕對距離總和
 *    `Σ|nums[i] - x|` 取最小值，數學上可以證明最佳的 x 是中位數
 *    （直覺理解：如果 x 比中位數小，往中位數方向移動一點點，會讓
 *    「比 x 大的那一半元素」的距離總和減少得比「比 x 小的那一半」
 *    增加得更多，因為兩側元素個數不平衡，所以要移到正中間才是
 *    最優）。
 * 3. 計算每個元素到中位數的絕對距離，加總就是答案。
 */
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        int moves = 0;
        for (int x : nums) moves += abs(x - median);
        return moves;
    }
};
