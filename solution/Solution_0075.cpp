/**
 * 題目：75. Sort Colors (顏色分類 / 荷蘭國旗問題)
 * 難度：中等 (Medium)
 * 描述：給定一個包含紅色、白色、藍色（分別用 0, 1, 2 表示）的陣列，
 *      原地 (In-place) 對它們進行排序，使得相同顏色的元素相鄰。
 * 
 * 時間複雜度：O(n) - 只需要遍歷一次陣列。
 * 空間複雜度：O(1) - 僅使用常數個額外空間。
 * 
 * 解法思路：
 * 使用三個指標來維護三個區域：
 * 1. red (左邊界)：[0, red-1] 全是 0 (紅色)。
 * 2. white (當前掃描)：[red, white-1] 全是 1 (白色)。
 * 3. blue (右邊界)：[blue+1, n-1] 全是 2 (藍色)。
 * 
 * 運作邏輯：
 * - 遇到 0：與 red 交換，因為 red 指向的位置一定是 1（或就是 white 自身），
 *          交換後 white 可以放心前進。
 * - 遇到 1：不需交換，white 直接前進。
 * - 遇到 2：與 blue 交換，但交換過來的數還沒看過（可能是 0, 1, 2），
 *          所以 white 指標不能移動，下一輪要重新檢查這個位置。
 */


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return;
        int red= 0;
        int white = 0;
        int blue = n -1;
        while(white <= blue) {
            if(nums[white] == 0) {
                swap(nums[white++], nums[red++]);
            } else if(nums[white] == 2) {
                swap(nums[white], nums[blue--]);
            } else {
                white++;
            }
        }
    }
};
