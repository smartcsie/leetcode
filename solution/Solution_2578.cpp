/**
 * 題目：2578. Split With Minimum Sum
 * 難度：簡單 (Easy)
 * 描述：將數字拆分為兩個數，使兩數之和最小。
 * 優化重點：
 * 1. 貪心策略：排序後交替分配，能保證較小的數字佔據更高位權重。
 * 2. 位元運算：使用 (i & 1) 代替 i % 2，程式碼更簡潔。
 *
 * 時間複雜度：O(NlogN)
 * 空間複雜度：O(N)
 */

class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        string s1, s2;
        for(int i = 0; i < s.size(); i++) {
            if(i & 1) s1.push_back(s[i]);
            else s2.push_back(s[i]);
        }
        return stoi(s1) + stoi(s2);
    }
};
