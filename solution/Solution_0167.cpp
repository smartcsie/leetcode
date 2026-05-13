/**
 * 解題思路：對撞指標 (Two Pointers)
 * 1. 由於陣列已經「由小到大排序」，我們可以使用兩個指標分別指向頭 (left) 與尾 (right)。
 * 2. 計算兩者的和 sum = numbers[left] + numbers[right]：
 *    - 如果 sum == target：找到答案，回傳索引。
 *    - 如果 sum < target：代表目前的和太小，應將 left 向右移，以增加總和。
 *    - 如果 sum > target：代表目前的和太大，應將 right 向左移，以減小總和。
 * 3. 題目要求回傳 1-based 的索引，因此結果要加 1。
 * 
 * Time Complexity: O(n) - 最多遍歷陣列一次。
 * Space Complexity: O(1) - 僅使用兩個指標，不需額外空間。
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        while(l < r) {
            int sum = numbers[l] + numbers[r];
            if( sum == target) {
                return {l + 1, r + 1};
            } else if(sum < target){
                l++;
            } else {
                r--;
            }
        }
        return {};
    }
};
