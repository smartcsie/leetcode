/**
 * 題目：705. Design HashSet (設計雜湊集合)
 * 難度：簡單 (Easy)
 * 描述：不使用內建的哈希表函式庫設計一個 HashSet。
 *
 * 時間複雜度：O(1)
 * 空間複雜度：O(M+N)
 *
 * 設計思路：
 * 1. 1. 使用一個固定大小的陣列作為「桶 (Buckets)」。
 * 2. 2. 每個桶內存放一個 list，處理衝突 (Collision)。
 * 3. 3. 雜湊函式：key % bucketSize。
 */

class MyHashSet {
private:
    vector<bool> set;
public:
    MyHashSet() : set(1000001, false) { }
    void add(int key) {
        set[key] = true;
    }
    void remove(int key) {
        set[key] = false;
    }
    bool contains(int key) {
        return set[key];
    }
};