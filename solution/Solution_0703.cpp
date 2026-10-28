/**
 * 題目：703. Kth Largest Element in a Stream (數據流中的第 K 大元素)
 * 難度：簡單 (Easy)
 * 描述：設計一個類別，在數據流中動態尋找第 K 大的元素。
 *
 * 時間複雜度：O(NlogK)
 * 空間複雜度：O(K)
 *
 * 解法思路：
 * 維護一個大小為 K 的最小堆。當堆內元素少於 K 個時直接插入；
 * 當超過 K 個時，若新元素大於堆頂，則彈出舊堆頂並壓入新元素。
 */

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        minHeap = priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.end());
        K = k;
        while(minHeap.size() > K) {
            minHeap.pop();
        }
    }
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > K) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};