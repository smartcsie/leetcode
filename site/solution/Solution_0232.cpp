/**
 * 題目：232. Implement Queue using Stacks (用堆疊實作佇列)
 * 難度：簡單 (Easy)
 * 描述：使用兩個堆疊來模擬佇列的 FIFO (先進先出) 操作。
 * * 時間複雜度：
 * - push: O(1)
 * - pop / peek: O(1) 攤提時間 (Amortized)，每個元素最多從 sIn 移到 sOut 一次。
 * 空間複雜度：O(N) - 儲存所有元素。
 */

class MyQueue x
private:
    stack<int> sIn, sOut;

    // 將 sIn 的元素全部轉移至 sOut，僅在 sOut 為空時呼叫
    void transfer() {
        if (sOut.empty()) {
            while (!sIn.empty()) {
                sOut.push(sIn.top());
                sIn.pop();
            }
        }
    }

public:
    MyQueue() {}
    
    void push(int x) {
        sIn.push(x);
    }
    
    int pop() {
        peek(); // 確保 sOut 有元素
        int res = sOut.top();
        sOut.pop();
        return res;
    }
    
    int peek() {
        transfer(); // 封裝轉移邏輯，增加可讀性
        return sOut.top();
    }
    
    bool empty() {
        return sIn.empty() && sOut.empty();
    }
};
