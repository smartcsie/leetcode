/**
 * 題目：287. Find the Duplicate Number
 * 難度：中等 (Medium)
 * 描述：找出陣列中重複的數字，不修改陣列且只用 O(1) 空間。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * （Negative Marking）：
 * 用負號標記已訪問過的 index，若發現對應位置已為負數，該 index+1 即為重複數字。
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;
            if(nums[idx] < 0) return idx + 1;
            nums[idx] = -nums[idx];
        }
        return -1;
    }
};