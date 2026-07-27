/**
 * 題目：11. Container With Most Water (盛最多水的容器)
 * 難度：中等 (Medium)
 * 描述：給定一個長度為 n 的整數陣列 height。有 n 條垂直線，第 i 條線的兩個端點分別為 (i, 0) 和 (i, height[i])。
 *      找出兩條線，它們與 x 軸共同構成一個容器，使得容器可以容納最多的水。
 * 
 * 時間複雜度：O(n) - 左右指標各遍歷一次陣列。
 * 空間複雜度：O(1) - 僅使用常數個變數。
 * 
 * 解法思路：
 * 1. 使用雙指標 (Two Pointers) 法，left 指向陣列開頭，right 指向陣列結尾。
 * 2. 容器的面積由「短板」決定：面積 = min(height[left], height[right]) * (right - left)。
 * 3. 貪婪策略 (Greedy)：
 *    - 每次計算完面積後，我們必須移動其中一個指標。
 *    - 因為向內移動會導致「寬度 (right - left)」減少，若想獲得更大面積，必須尋找更高的「高度」。
 *    - 若移動較長的那一邊，受限於短邊，面積只會變小；因此，我們必須移動「較短」的那一邊。
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int res = 0;
        while(left < right){
            int h = min(height[left],height[right]);
            int w = right-left;
            res = max(res, h  *w);
            if(height[left] < height[right]) left++;
            else right--;
        }
        return res;
    }
};
