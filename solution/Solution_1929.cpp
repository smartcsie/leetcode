/**
 * 題目：1929. Concatenation of Array (串聯陣列)
 * 難度：簡單 (Easy)
 * 描述：給定一個長度為 n 的陣列 nums，請回傳一個長度為 2n 的陣列 ans，
 * 其中 ans 是由兩個 nums 串聯而成。
 * * 時間複雜度：O(N) - 遍歷原陣列一次。
 * 空間複雜度：O(1) - 不考慮回傳值所佔用的空間。
 * * 解法思路：
 * 1. 取得原陣列長度 n。
 * 2. 遍歷原陣列的每個元素，將其追加 (push_back) 到陣列末尾。
 * 3. 由於 vector 會在空間不足時自動擴充，此法能有效達成連接。
 */

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        // 預留空間可減少擴充時的記憶體分配開銷 (Optional)
        nums.reserve(2 * n);
        
        for (int i = 0; i < n; i++) {
            nums.push_back(nums[i]);
        }
        
        return nums;
    }
};
