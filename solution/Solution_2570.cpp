/**
 * 題目：2570. Merge Two 2D Arrays by Summing Values (合併兩個二維陣列求和)
 * 難度：簡單 (Easy)
 * 描述：給你兩個二維整數陣列 nums1 和 nums2。
 *       - nums1[i] = [idi, vali]，表示編號 idi 的元素其值為 vali。
 *       - nums2[i] = [idi, vali]，表示編號 idi 的元素其值為 vali。
 *       兩個陣列都已經按照 id 嚴格遞增排序，且 id 都是唯一的。
 *       請你合併這兩個陣列，並返回一個按照 id 遞增排序的新二維陣列。如果相同的 id 同時存在於兩個陣列中，其值相加。
 * 
 * 時間複雜度：O(N+M)
 * 空間複雜度：O(1)
 * 
 * 解法思路：
 * 1. 利用有序特性 (Two Pointers)：
 *    - 題目保證 `nums1` 與 `nums2` 的 id 都是遞增排序的。這與「合併兩個有序鏈結串列/陣列」的概念完全一致。
 * 2. 雙指標同步比對：
 *    - 使用指標 `i` 與 `j` 分別追蹤兩個陣列的當前位置。
 *    - 當 `nums1[i][0] == nums2[j][0]`：id 相同，將兩者的值相加並放入 `ans`，兩指標同時向右移動。
 *    - 當 `nums1[i][0] < nums2[j][0]`：`nums1` 的 id 較小，直接將該項放入 `ans`，指標 `i` 向右移動。
 *    - 當 `nums1[i][0] > nums2[j][0]`：`nums2` 的 id 較小，直接將該項放入 `ans`，指標 `j` 向右移動。
 * 3. 處理剩餘元素：
 *    - 當其中一個陣列走訪完畢時，將另一個陣列剩下的所有元素直接全部接在 `ans` 後方。
 */


class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int i = 0, j = 0;
        vector<vector<int>> ans;
        ans.reserve(m + n);
        while(i < m && j < n) {
            if(nums1[i][0] == nums2[j][0]) 
                ans.push_back({nums1[i][0], nums1[i++][1] + nums2[j++][1]});
            else if(nums1[i][0] < nums2[j][0])
                ans.push_back(nums1[i++]);
            else  
                ans.push_back(nums2[j++]);
            
        }
        while(i < m) ans.push_back(nums1[i++]);
        while(j < n) ans.push_back(nums2[j++]);
        return ans;
    }
};
