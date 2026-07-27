/**
 * 題目：703. Kth Largest Element in a Stream (數據流中的第 K 大元素)
 * 難度：簡單 (Easy)
 * 描述：設計一個類別，在數據流中動態尋找第 K 大的元素。
 * * 時間複雜度：
 * - 初始化：O(N log K)，N 為初始陣列大小。
 * - add 操作：O(log K)。
 * 空間複雜度：O(K) - 堆中始終只存 K 個元素。
 * * 優化思路：
 * 維護一個大小為 K 的最小堆。當堆內元素少於 K 個時直接插入；
 * 當超過 K 個時，若新元素大於堆頂，則彈出舊堆頂並壓入新元素。
 */

class KthLargest {
private:
    // 使用最小堆 (greater<int>)，堆頂永遠是最小的元素
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int K;
    
public:
    KthLargest(int k, vector<int>& nums) : K(k) {
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        // 如果堆未滿，直接加入
        if (minHeap.size() < K) {
            minHeap.push(val);
        } 
        // 如果堆已滿，且新值大於堆頂，則替換堆頂
        else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }
        
        return minHeap.top();
    }
};
