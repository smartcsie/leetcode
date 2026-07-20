/**
 * 題目：599. Minimum Index Sum of Two Lists
 * 描述：給定兩個字串陣列 list1 和 list2，找出同時存在於兩者中、且索引和（index sum）最小的餐廳。
 *       若有多個相同最小和的餐廳，則全部回傳。
 * 
 * 解法思路：
 * 1. 使用 unordered_map 將 list2 的每個字串與其索引建立映射關係 (string -> index)。
 * 2. 遍歷 list1，若當前字串存在於 map2 中，計算兩者的索引和 (idx1 + idx2)。
 * 3. 維護一個 minIdx 記錄目前最小的索引和：
 *    - 若小於 minIdx，更新 minIdx 並清空舊答案，放入新字串。
 *    - 若等於 minIdx，將該字串加入答案陣列中。
 */

class Solution {
public:
    std::vector<std::string> findRestaurant(std::vector<std::string>& list1, std::vector<std::string>& list2) {
        std::unordered_map<std::string, int> map2;
        // 1. 將 list2 建立雜湊表，key 為餐廳名稱，value 為其索引
        for (int i = 0; i < list2.size(); ++i) {
            map2[list2[i]] = i;
        }
        int minIdx = INT_MAX;
        std::vector<std::string> ans;
        // 2. 遍歷 list1 尋找交集並計算索引和
        for (int i = 0; i < list1.size(); i++) {
            std::string str = list1[i];
            // 使用 find 檢查是否同時存在於 list2 中
            if (map2.find(str) != map2.end()) {
                int idx1 = i;
                int idx2 = map2[str];
                int currentSum = idx1 + idx2;
                // 3. 根據索引和更新最佳解
                if (currentSum < minIdx) {
                    minIdx = currentSum;
                    ans = {str}; // 發現更小的和，重置答案
                } else if (currentSum == minIdx) {
                    ans.push_back(str); // 發現相同的最小和，加入清單
                }
            }
        }
        return ans;
    }
};
