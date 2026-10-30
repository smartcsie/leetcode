/**
 * 題目：1881. Maximum Value after Insertion
 * 難度：中等 (Medium)
 * 描述：在字串形式的數字中插入一個數值 x，使最終結果最大。
 * 優化重點：
 * 1. 貪婪搜索：單次遍歷即可找到最佳插入位置，O(N)。
 * 2. 條件分流：針對正負號分別採用不同的貪婪條件。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    string maxValue(string n, int x) {
        int idx = 0;
        char c = x + '0';
        if(n[0] == '-') {
            idx++;
            while(idx < n.size() && c >= n[idx]) idx++;
        } else {
            while(idx < n.size() && c <= n[idx]) idx++;
        }
        n.insert(n.begin() + idx , c);
        return n;
    }
};