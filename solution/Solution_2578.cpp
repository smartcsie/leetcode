/**
 * 題目：2578. Split With Minimum Sum
 * 難度：簡單 (Easy)
 * 描述：將數字拆分為兩個數，使兩數之和最小。
 * * 優化重點：
 * 1. 貪心策略：排序後交替分配，能保證較小的數字佔據更高位權重。
 * 2. 位元運算：使用 (i & 1) 代替 i % 2，程式碼更簡潔。
 */

class Solution {
public:
    int splitNum(int num) {
        std::string s = std::to_string(num);
        std::sort(s.begin(), s.end());
        
        int num1 = 0, num2 = 0;
        for(int i = 0; i < s.size(); i++) {
            // 奇數索引分給 num1，偶數索引分給 num2
            if(i & 1) num1 = num1 * 10 + (s[i] - '0');
            else num2 = num2 * 10 + (s[i] - '0');
        }
        
        return num1 + num2;
    }
};
