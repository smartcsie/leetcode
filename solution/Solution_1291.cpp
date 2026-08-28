/**
 * 題目：1291. Sequential Digits
 * 難度：中等 (Medium)
 * 描述：找出所有範圍 [low, high] 內的「順序數字」。
 * 優化重點：
 * 1. 窮舉法：所有可能的順序數字總共不超過 40 個，窮舉最快。
 * 2. 字串截取：利用 "123456789" 作為模板進行截取。
 *
 * 時間複雜度：O(1)
 * 空間複雜度：O(1)
 */

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        queue<int> q;
        for (int i = 1; i <= 9; ++i) q.push(i);
        while (!q.empty()) {
            int num = q.front(); q.pop();
            if (num >= low && num <= high) res.push_back(num);
            if (num > high) break;
            int d = num % 10;
            if (d < 9) q.push(num * 10 + d + 1);
        }
        return res;
    }
};
