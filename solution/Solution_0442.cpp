/**
 * 題目：442. Find All Duplicates in an Array (陣列中重複的數字)
 * 難度：中等 (Medium)
 * 描述：在長度為 n 的陣列中，每個整數出現一次或兩次，找出所有出現兩次的整數。
 * * 時間複雜度：O(N) - 遍歷陣列一次。
 * 空間複雜度：O(1) - 原地標記，不計算回傳陣列所需的空間。
 * * 解法思路：
 * 1. 遍歷陣列，對於每個值 `abs(num)`，將其作為索引指向 `nums[abs(num) - 1]`。
 * 2. 如果該索引位置的值為正，將其變為負數，表示「該數字已出現過」。
 * 3. 如果該索引位置的值已經為負，說明之前已經造訪過此索引，故該數字即為重複值。
 */

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        
        for (int num : nums) {
            // 使用 abs() 取值，因為數字可能已經被轉為負數
            int idx = abs(num) - 1;
            
            // 如果該位置已是負數，表示之前已經處理過該索引，因此該數字為重複項
            if (nums[idx] < 0) {
                res.push_back(abs(num));
            } else {
                // 將對應位置標記為負數
                nums[idx] *= -1;
            }
        }
        
        return res;
    }
};
