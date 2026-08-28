/**
 * 題目：599. Minimum Index Sum of Two Lists
 * 難度：待補充
 * 描述：給定兩個字串陣列 list1 和 list2，找出同時存在於兩者中、且索引和（index sum）最小的餐廳。
 * 若有多個相同最小和的餐廳，則全部回傳。
 *
 * 時間複雜度：O(N+M)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 1. 使用 unordered_map 將 list2 的每個字串與其索引建立映射關係 (string -> index)。
 * 2. 遍歷 list1，若當前字串存在於 map2 中，計算兩者的索引和 (idx1 + idx2)。
 * 3. 維護一個 minIdx 記錄目前最小的索引和：
 * - 若小於 minIdx，更新 minIdx 並清空舊答案，放入新字串。
 * - 若等於 minIdx，將該字串加入答案陣列中。
 */

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> r2i;
        for(int i = 0; i < list1.size(); i++) r2i[list1[i]] = i;
        int minIdx = 2001;
        vector<string> ans;
        for(int idx2 = 0; idx2 < list2.size(); idx2++) {
            string& restaurant = list2[idx2];
            if(r2i.contains(restaurant)) {
                int idx1 = r2i[restaurant];
                if(idx1 + idx2 < minIdx) {
                    minIdx = idx1 + idx2;
                    ans = {restaurant};
                } else if(idx1 + idx2 == minIdx) {
                    ans.push_back(restaurant);
                } 
            }
        }
        return ans;
    }
};
