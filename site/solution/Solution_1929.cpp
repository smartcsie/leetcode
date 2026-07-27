/**
 * 題目：1929. Concatenation of Array (串聯陣列)
 * 難度：簡單 (Easy)
 * 描述：返回一個長度為 2n 的陣列，其中 ans[i] == nums[i] 且 ans[i + n] == nums[i]。
 * * 時間複雜度：O(N) - 遍歷一次陣列。
 * 空間複雜度：O(N) - 輸出陣列長度為 2N。
 * * 優化思路：
 * 1. 使用 reserve 預先分配記憶體是正確的優化。
 * 2. 也可以直接使用 vector 的建構子或是 insert 語法，這在內部執行上通常會被優化為 memmove。
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans = nums;
        ans.reserve(n * 2);     
        ans.insert(ans.end(), nums.begin(), nums.end());
        return ans;
    }
};
