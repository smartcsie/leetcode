/**
 * 題目：234. Palindrome Linked List (回文鏈表)
 * 難度：簡單 (Easy)
 * 描述：給你一個單鏈表的頭節點 head，請判斷該鏈表是否為回文。
 *      如果是，返回 true；否則，返回 false。
 * 
 * 時間複雜度：O(n) - 需要遍歷一遍鏈表來提取數值，再遍歷一半陣列進行檢查。
 * 空間複雜度：O(n) - 使用了一個 vector 來儲存鏈表中的所有數值。
 * 
 * 解法思路：
 * 1. 特殊情況處理：若鏈表為空或只有一個節點，直接判定為回文。
 * 2. 轉存陣列：遍歷整個鏈表，將每個節點的 val 依序放入 vector<int> 中。
 * 3. 雙指標檢查：
 *    - 設定頭指標 i = 0 與尾指標 j = size - 1。
 *    - 當 i < j 時，比較兩者數值是否相等。
 *    - 只要有一次不等即回傳 false，若全部比對完成則回傳 true。
 */

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        vector<int> nums;
        ListNode* cur = head;
        while(cur) {
            nums.push_back(cur->val);
            cur = cur->next;
        }
        for(int i = 0 , j = nums.size() - 1; i < j; i++, j-- ) {
            if(nums[i] != nums[j]) return false;
        }
        return true;
    }
};
