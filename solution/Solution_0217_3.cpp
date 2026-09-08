/**
 * 題目：217. Contains Duplicate
 * 難度：簡單 (Easy)
 * 描述：判斷陣列中是否有重複元素。
 *
 * 時間複雜度：O(NlogN)
 * 空間複雜度：O(logN)
 *
 * 解法思路：
 * （排序後檢查相鄰元素）：
 * 排序後，若有重複元素必然相鄰，逐一比較相鄰元素即可。
 */
public:
    bool containsDuplicate(vector<int>& nums) {
        ranges::sort(nums);
        for (int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1]) return true;
        }
        return false;
    }
};