/**
 * 題目：2418. Sort the People (按身高排序)
 * 難度：簡單 (Easy)
 * 描述：給定一個名字陣列 names 和一個身高陣列 heights，
 *       將所有人按照身高從高到低（降冪）排序，並返回排序後的姓名陣列。
 * 
 * 時間複雜度：O(N log N)
 * 空間複雜度：O(N)
 * 
 * 解法思路 (間接排序 / Indirect Sorting)：
 * 1. 建立一個大小為 N 的索引陣列 `indices`，內容為 0 到 N-1。
 * 2. 使用 `std::sort` 對 `indices` 進行排序，在比較時依據 `heights[a] > heights[b]` 
 *    來決定身高由高到低的順序（降冪）。
 * 3. 根據排序後的 `indices` 順序，依序將對應的 `names[idx]` 放入結果集 `ans` 中並返回。
 */

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<int> indices(n);
        for(int i = 0; i < n; i++) indices[i] = i;
        sort(indices.begin(), indices.end(), [&](const int& a, const int& b){
            return heights[a] > heights[b];
        });
        vector<string>ans;
        ans.reserve(n);
        for(const int& idx : indices) {
            ans.push_back(names[idx]);
        }
        return ans;
    }
};