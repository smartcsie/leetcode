/**
 * 題目：3442. Maximum Difference Between Even and Odd Frequency I
 * 難度：簡單 (Easy)
 * 描述：計算字串中「奇數頻率的最大值」與「偶數頻率的最小值」之差。
 * 
 * 解法思路：
 * 1. 使用長度為 26 的陣列記錄每個字母的出現頻率。
 * 2. 遍歷字串統計頻率。
 * 3. 再次遍歷陣列，分別維護 `maxOdd` 與 `minEven` 的記錄。
 * 4. 最後返回 `maxOdd - minEven`。
 */

class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        int maxOdd = 0, minEven = INT_MAX;
        for(char& c : s) {
            freq[c - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0) continue;
            if(freq[i] & 1) {
                maxOdd = max(maxOdd, freq[i]);
            } else {
                minEven = min(minEven, freq[i]);
            }
        }
        return maxOdd - minEven ;
    }
};
