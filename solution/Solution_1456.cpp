/**
 * 題目：1456. Maximum Number of Vowels in a Substring of Given Length
 * 難度：中等 (Medium)
 * 描述：找出長度為 k 的子字串中，包含最多母音的數量。
 * * 時間複雜度：O(N) - 遍歷字串一次。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 設計思路：
 * 1. 先計算前 k 個字元的母音數量作為視窗初始值。
 * 2. 透過滑動視窗 (Sliding Window) 向右遍歷，每次加入新字元並移除最舊字元。
 * 3. 若計數達到 k，即為最大值，直接返回結果以節省時間。
 */

class Solution {
private:
    // 輔助函式：判斷是否為母音
    inline bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int maxVowel = 0;
        int currVowel = 0;
        
        // 初始化第一個視窗 (前 k 個)
        for (int i = 0; i < k; ++i) {
            if (isVowel(s[i])) currVowel++;
        }
        
        maxVowel = currVowel;
        
        // 開始滑動視窗
        for (int i = k; i < n; ++i) {
            // 加入新字元
            if (isVowel(s[i])) currVowel++;
            // 移除舊字元
            if (isVowel(s[i - k])) currVowel--;
            
            // 更新最大值
            maxVowel = max(maxVowel, currVowel);
            
            // 若找到最大可能值 k，提早返回
            if (maxVowel == k) return k;
        }
        
        return maxVowel;
    }
};
