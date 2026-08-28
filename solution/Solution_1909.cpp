/**
 * 題目：1909. Remove One Element to Make the Array Strictly Increasing (刪除一個元素使陣列嚴格遞增)
 * 難度：簡單 (Easy)
 * 描述：給定整數陣列 nums，判斷是否能透過刪除「至多一個」元素，
 *       使剩餘陣列變成嚴格遞增。若陣列本身已經是嚴格遞增，也視為可行。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 *
 * 解法思路：
 * 1. 定義驗證函式 check(k)：跳過索引 k 後，檢查整個陣列是否嚴格遞增 (Full Re-verification)：
 *    - 走訪整個陣列，唯獨跳過索引 k 這個元素，用 pre 追蹤上一個保留下來的值，
 *      只要遇到 pre >= nums[i]，代表不嚴格遞增，回傳 false。
 * 2. 找出第一個破壞遞增的位置 (First Break Point)：
 *    - 用 while 迴圈往前推進 i，只要 nums[i] < nums[i+1] 就持續前進，
 *      直到遇到第一個 nums[i] >= nums[i+1] 的位置停下（或走到底代表陣列本身已遞增）。
 * 3. 只需檢查兩個候選移除點 (Only Two Candidates Matter)：
 *    - 若真的存在某個單一移除方式能修好整個陣列，該移除的元素必定就是造成第一個斷點的
 *      索引 i 或索引 i+1 之一，因為斷點之前的部分已經確定是合法遞增，
 *      移除其他位置的元素不可能修復這個「最早出現」的斷點。
 * 4. 全域重新驗證確保後續也無誤：
 *    - check(i) 或 check(i+1) 各自對整個陣列重新掃描一次，
 *      不只局部檢查第一個斷點，也能同時捕捉陣列後段是否還存在其他無法修復的斷點。
 * 5. 邊界情況：陣列本身已遞增：
 *    - 此時 i 會停在 n-1，check(n) 因為索引 k=n 永遠不等於迴圈中的 i（範圍是 0~n-1），
 *      等同於完全不跳過任何元素、直接檢查原陣列，天然涵蓋「不需移除也成立」的情況。
 */
class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        auto check = [&](int k) {
            int pre = INT_MIN;
            for (int i = 0; i < n; i++) {
                if (i == k) continue;
                if (pre >= nums[i]) return false;
                pre = nums[i];
            }
            return true;
        };

        int i = 0;
        while (i + 1 < n && nums[i] < nums[i + 1]) i++;
        return check(i) || check(i + 1);
    }
};
