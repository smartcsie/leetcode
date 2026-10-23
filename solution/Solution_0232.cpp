/**
 * 題目：232. Implement Queue using Stacks (用堆疊實作佇列)
 * 難度：簡單 (Easy)
 * 描述：使用兩個堆疊來模擬佇列的 FIFO (先進先出) 操作。
 *
 * 時間複雜度：O(1)
 * 空間複雜度：O(N)
 */

class MyQueue {
private:
    stack<int> inStack;
    stack<int> outStack;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        inStack.push(x);
    }
    
    int pop() {
        int key = peek();
        outStack.pop();
        return key;
    }
    
    int peek() {
        if(outStack.empty()) {
            while(!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();
    }
    
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};