
/**
 * 解題思路：雙指標法 (Two Pointers)
 * 1. 觀察：原陣列已排序，但包含負數。平方後，最大的數一定會出現在「最左端」或「最右端」。
 * 2. 策略：
 *    - 使用 left 指向 0，right 指向 n-1。
 *    - 建立一個等長的結果陣列 ans，並從「最後一個位置」開始填入。
 *    - 比較 nums[left] 和 nums[right] 的絕對值（或平方值）：
 *        - 若右邊大，填入右邊平方，right 左移。
 *        - 若左邊大，填入左邊平方，left 右移。
 * 3. 為什麼不直接平方後 sort？
 *    - 直接 sort 的時間複雜度是 O(n log n)。
 *    - 使用雙指標只需 O(n)，效率更高。
 * 
 * Time Complexity: O(n) - 遍歷陣列一次。
 * Space Complexity: O(n) - 需要一個額外空間存儲結果（若不計回傳空間則為 O(1)）。
 */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int i = 0;
        int j = n - 1;
        for(int k = n - 1 ; k >= 0 ; k--) {
            if(abs(nums[i]) > abs(nums[j])) {
                res[k] = nums[i]*nums[i];
                i++;
            } else {
                res[k] = nums[j]*nums[j];
                j--;
            }
        }
        return res;
    }
};
