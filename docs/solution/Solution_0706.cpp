class MyHashMap {
private:
    // 使用一個陣列，每個陣列元素是一個「桶子」(Bucket)，桶子用 vector 儲存 key-value pair
    vector<list<pair<int, int>>> buckets;
    static const int SIZE = 1000; // 桶子的數量

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() : buckets(SIZE) {}

    void put(int key, int value) {
        int idx = hash(key);
        for (auto& p : buckets[idx]) {
            if (p.first == key) {
                p.second = value; // 更新現有的值
                return;
            }
        }
        buckets[idx].push_back({key, value}); // 新增新的 pair
    }

    int get(int key) {
        int idx = hash(key);
        for (auto& p : buckets[idx]) {
            if (p.first == key) return p.second;
        }
        return -1;
    }

    void remove(int key) {
        int idx = hash(key);
        auto& bucket = buckets[idx];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};
