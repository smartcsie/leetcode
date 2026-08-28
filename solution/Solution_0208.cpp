/**
 * 題目：208. Implement Trie (Prefix Tree)
 * 難度：中等 (Medium)
 * 描述：實作一個 Trie（前綴樹），支援插入字串、搜尋字串、搜尋前綴三種操作。
 *
 * 時間複雜度：O(L) - L 為字串長度，insert / search / startsWith 皆為 O(L)。
 * 空間複雜度：O(N * L) - N 為插入字串數量，L 為平均長度。
 *
 * 解法思路：
 * （Trie 節點陣列）：
 * 1. 每個節點包含 26 個子節點指針（對應 a~z）和一個 isEnd 旗標。
 * 2. insert：逐字元走訪，若子節點不存在則建立，最後標記 isEnd = true。
 * 3. search：用 find 走到字串末端節點，檢查 isEnd 是否為 true。
 * 4. startsWith：用 find 走到前綴末端節點，只要節點存在即回傳 true。
 * 5. find 為私有輔助函式，供 search 和 startsWith 共用，避免重複程式碼。
 */
class Trie {
    Trie* children[26] = {};  // 26 個子節點，自動初始化為 nullptr
    bool isEnd = false;       // 標記此節點是否為某個字串的結尾
public:
    Trie() {}

    void insert(string word) {
        Trie* curr = this;
        for (char c : word) {
            int i = c - 'a';
            if (!curr->children[i]) curr->children[i] = new Trie();
            curr = curr->children[i];
        }
        curr->isEnd = true;
    }

    bool search(string word) {
        Trie* curr = find(word);
        return curr && curr->isEnd;  // 節點存在且是字串結尾
    }

    bool startsWith(string prefix) {
        return find(prefix) != nullptr;  // 節點存在即有此前綴
    }

private:
    // 走訪到 prefix 末端節點，找不到回傳 nullptr
    Trie* find(string& prefix) {
        Trie* curr = this;
        for (char c : prefix) {
            int i = c - 'a';
            if (!curr->children[i]) return nullptr;
            curr = curr->children[i];
        }
        return curr;
    }
};
