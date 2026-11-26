/*
 * 題目：2570. Merge Two 2D Arrays by Summing Values
 * 難度：Easy
 * 描述：給定兩個二維陣列 nums1、nums2，每個元素是 [id, val]，且各自已依 id 嚴格遞增排序、id 不重複。合併成一個依 id 遞增的陣列：兩邊都有的 id，值相加；只有一邊有的 id，值不變（視為另一邊為 0）。
 * 分類主題：two-pointers-same
 * 技巧：雙指標合併已排序陣列, 相同 id 相加, 收尾搬運剩餘元素
 * 時間複雜度：O(m + n)
 * 空間複雜度：O(1)（不含輸出）
 * 解法思路：
 *   1. 兩個陣列都已依 id 排序，像合併兩個有序串列一樣，用 i、j 各自指向目前元素
 *   2. id 相同：把兩邊的值相加，放入結果，兩個指標都往前
 *   3. nums1 的 id 較小：它在 nums2 中不存在，直接放入結果，i 往前
 *   4. nums2 的 id 較小：同理，直接放入結果，j 往前
 *   5. 其中一邊走完後，把另一邊剩下的元素依序接到結果後面（剩下的 id 一定都更大，且已排序）
 */
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i = 0, j = 0;
        vector<vector<int>> ans;
        while((i < nums1.size()) && (j < nums2.size())) {
            if(nums1[i][0] == nums2[j][0]) {
                // 兩邊都有這個 id：值相加，兩個指標一起前進
                ans.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            } else if(nums1[i][0] < nums2[j][0]) {
                // 只有 nums1 有這個 id：原樣放入
                ans.push_back(nums1[i++]);
            } else {
                // 只有 nums2 有這個 id：原樣放入
                ans.push_back(nums2[j++]);
            }
        }
        // 其中一邊用完，另一邊剩下的 id 都更大，依序接上即可
        while(i < nums1.size()) ans.push_back(nums1[i++]);
        while(j < nums2.size()) ans.push_back(nums2[j++]);
        return ans;
    }
};