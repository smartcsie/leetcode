/**
 * 題目：55. Jump Game
 * 難度：中等 (Medium)
 * 描述：判斷是否能從陣列起點跳到終點。
 * * 優化重點：
 * 1. 貪心策略：維護一個 `maxReach` 變數，紀錄當前能到達的最遠位置。
 * 2. 提前中斷：若發現目前位置 `i` 超過了 `maxReach`，代表無法再繼續前進，直接回傳 false。
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;
        for(int i =0; i < n; i++) {
            if(i > maxReach) return false;
            maxReach = max(maxReach, i + nums[i]);
            if(maxReach >= n - 1) return true;
        }
        return true;
    }
};
