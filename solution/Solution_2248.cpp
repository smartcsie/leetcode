/**
 * 題目：2248. Intersection of Multiple Arrays
 * 難度：簡單 (Easy)
 * 描述：找出所有陣列中共同出現的元素，回傳排序後的結果。
 * 時間複雜度：O(N*M)
 * 空間複雜度：O(N)

 */
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        array<uint16_t, 1001> counts;
        int n = nums.size();
        vector<int> ans;
        for(const vector<int>& v : nums) {
            for(const int& num : v) {
                counts[num]++;
            }
        }
        for(int i = 1; i <= 1000; i++) {
            if(counts[i] == n) ans.push_back(i);
        }
        return ans;
    }
};