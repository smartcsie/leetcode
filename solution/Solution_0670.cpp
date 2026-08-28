/**
 * 題目：670. Maximum Swap
 * 難度：中等 (Medium)
 * 描述：在最多一次交換下，求出能得到的最大數字。
 * 優化重點：
 * 1. 預處理：使用 last_idx 陣列紀錄每個數字最後出現的位置，確保交換時能選到「最右邊」的大數。
 * 2. 貪心策略：由左至右尋找第一個能被交換以變大的高位數字。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        for(int i = 0; i < s.size(); i++) {
            char mxCh = 0;
            int maxIdx = 0;
            for(int j = i + 1; j < s.size(); j++) {
                if(s[j] >= mxCh) {
                    maxIdx = j;
                    mxCh = s[j];
                } 
            }
            if(mxCh > s[i]) {
                swap(s[i], s[maxIdx]);
                return stoi(s);
            }
        }
        return num;
    }
};
