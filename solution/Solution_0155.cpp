/**
 * 題目：155. Min Stack (最小堆疊)
 * 難度：中等 (Medium)
 * 描述：設計一個堆疊，除了標準功能外，還能以 O(1) 時間獲取最小值。
 * * 時間複雜度：O(1) - 所有操作（push, pop, top, getMin）均為常數時間。
 * 空間複雜度：O(N) - 輔助堆疊空間隨元素數量線性增長。
 * * 設計思路：
 * 使用兩個堆疊，`stk1` 負責存入原始資料，`min_stk` 負責維護最小值。
 * 若新元素比目前最小值小，則將其壓入 `min_stk`。
 */

class MinStack {
private:
    stack<int> stk;       // 儲存實際元素
    stack<int> min_stk;   // 儲存歷史最小值

public:
    MinStack() {}
    
    void push(int val) {
        stk.push(val);
        // 如果輔助堆疊為空，或者新值比目前最小值還小（或相等）
        if (min_stk.empty() || val <= min_stk.top()) {
            min_stk.push(val);
        }
    }
    
    void pop() {
        // 如果要彈出的元素剛好是目前的最小值，min_stk 也必須一起彈出
        if (stk.top() == min_stk.top()) {
            min_stk.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};
