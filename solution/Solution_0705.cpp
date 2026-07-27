/**
 * 題目：705. Design HashSet (設計雜湊集合)
 * 難度：簡單 (Easy)
 * 描述：不使用內建的哈希表函式庫設計一個 HashSet。
 * * 時間複雜度：O(1) - 平均情況下。
 * 空間複雜度：O(M + N) - M 為桶的數量，N 為插入的元素數量。
 * * 設計思路：
 * 1. 使用一個固定大小的陣列作為「桶 (Buckets)」。
 * 2. 每個桶內存放一個 list，處理衝突 (Collision)。
 * 3. 雜湊函式：key % bucketSize。
 */

class MyHashSet {
public:
    unordered_set<int> set;
    MyHashSet() {
        
    }
    
    void add(int key) {
        set.insert(key);
    }
    
    void remove(int key) {
        set.erase(key);
    }
    
    bool contains(int key) {
        return set.find(key) != set.end();
    }
};
