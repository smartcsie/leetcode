/**
 * 題目：225. Implement Stack using Queues (用佇列實作堆疊)
 * 難度：簡單 (Easy)
 * 描述：僅使用兩個佇列的特性來實現堆疊的 LIFO 操作。
 * * 時間複雜度：
 * - push: O(N) - 每次入棧需移動 N 個元素。
 * - pop/top: O(1) - 直接存取前端。
 * 空間複雜度：O(N) - 使用一個佇列儲存元素。
 */

#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {}
    
    // 將新元素 push 進來後，將 q.size()-1 個元素重新 pop 並 push 回 q
    // 這樣新元素就會排在 queue 的最前面
    void push(int x) {
        q.push(x);
        int size = q.size();
        while (size > 1) {
            q.push(q.front());
            q.pop();
            size--;
        }
    }
    
    // pop 直接移除 queue 前端即可
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    // top 直接取 queue 前端即可
    int top() {
        return q.front();
    }
    
    // empty 檢查 queue 是否為空
    bool empty() {
        return q.empty();
    }
};
