/**
 * 題目：2191. Sort the Jumbled Numbers (將標記轉換後的陣列排序)
 * 難度：中等 (Medium)
 * 描述：給定映射表 mapping（把 0~9 每個數字換成另一個數字）與陣列 nums，
 *       每個數字依照 mapping 轉換後得到「映射值」，
 *       請依照映射值由小到大排序 nums（映射值相同時保留原本相對順序）。
 *
 * 時間複雜度：O(NlogN)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 1. 逐位計算映射值 (Digit Mapping)：
 *    - 對每個數字，從個位數開始逐位取出，透過 mapping 轉換後乘上對應的位權（1, 10, 100...）累加。
 *    - 使用 do-while 迴圈確保數字為 0 時，也能正確計算 mapping[0] 這一位。
 * 2. 建立 (映射值, 原始索引) 配對：
 *    - 把每個數字的映射值與其原始索引存成 pair，方便排序後找回原始數字。
 * 3. 穩定排序 (Stable Sort by Pair)：
 *    - 對 pairs 依照映射值排序，pair 預設比較會先比第一個元素（映射值），
 *      相同時再比第二個元素（原始索引），恰好符合「映射值相同時保留原順序」的需求。
 * 4. 依排序後的索引取回原始數字：
 *    - 走訪排序後的 pairs，用其中的索引到原本的 nums 取值，組成最終答案。
 */
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<int> indices(n);
        vector<int> jumble(n);
        for(int i = 0; i < n; i++) {
            int jum = 0;
            if (nums[i] == 0) jum = mapping[0];
            else {
                int base = 1;
                int t = nums[i];
                while (t > 0) {
                    jum += mapping[t % 10] * base;
                    t /= 10;
                    base *= 10;
                }
            }
            jumble[i] = jum;
        }
        iota(indices.begin(), indices.end(), 0);
        stable_sort(indices.begin(), indices.end(), [&](const int& a, const int& b){
            return jumble[a] < jumble[b];
        });
        vector<int> ans;
        ans.reserve(n);
        for(const int& idx : indices) {
            ans.push_back(nums[idx]);
        }
        return ans;
    }
};
