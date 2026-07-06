/**
 * 題目：3884. First Matching Character From Both Ends
 * 難度：簡單 (Easy)
 * 描述：在字串中找到第一個左右指標指向相同字元的索引位置。
 * * 優化重點：
 * 1. 雙指標法 (Two-pointers)：同時從頭 (left) 與尾 (right) 進行檢查，將複雜度壓縮至單次遍歷。
 * 2. 提前中斷：一旦找到符合條件的字元，立即返回結果，達到最佳效能。
 */


class Solution {
public:
    int firstMatchingIndex(std::string s) {
        int left = 0;
        int right = s.size() - 1;
        
        // 雙指標向中間收斂
        while (left <= right) {
            // 如果兩端字元相等，返回左側指標位置
            if (s[left] == s[right]) {
                return left;
            }
            left++;
            right--;
        }
        
        // 若遍歷完成仍無匹配，返回 -1
        return -1;
    }
};
