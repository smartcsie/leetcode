/**
 * 題目：682. Baseball Game (棒球比賽)
 * 難度：簡單 (Easy)
 * 描述：根據一系列操作（數字、C、D、+）計算棒球比賽的最終分數。
 * * 時間複雜度：O(N) - 遍歷操作陣列一次。
 * 空間複雜度：O(N) - 使用 Stack 儲存分數。
 * * 解法思路：
 * 利用 Stack 模擬遊戲過程，並在最後將所有分數累加。
 */

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;
        // 預分配空間以避免多次重新配置記憶體
        scores.reserve(operations.size());
        
        for (const string& op : operations) {
            if (op == "C") {
                scores.pop_back();
            } else if (op == "D") {
                scores.push_back(scores.back() * 2);
            } else if (op == "+") {
                // scores.back() 是最後一個元素，*(scores.end() - 2) 是倒數第二個
                scores.push_back(scores.back() + *(scores.end() - 2));
            } else {
                scores.push_back(stoi(op));
            }
        }
        
        // 使用 accumulate 計算總和
        return accumulate(scores.begin(), scores.end(), 0);
    }
};
