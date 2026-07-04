/**
 * 題目：648. Replace Words
 * 難度：中等 (Medium)
 * 描述：將句子中的單字替換為字典中的最短前綴（Root）。
 * * 優化重點：
 * 1. 使用 Trie 取代 `vector<vector<string>>`：將前綴匹配複雜度從 O(詞彙數量) 降至 O(單字長度)。
 * 2. 記憶體預分配：使用 Trie 節點結構減少字串比對開銷。
 */


struct TrieNode {
    TrieNode* children[26] = {nullptr};
    bool isEndOfWord = false;
};

class Solution {
    TrieNode* root = new TrieNode();

    void insert(const std::string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children[c - 'a']) curr->children[c - 'a'] = new TrieNode();
            curr = curr->children[c - 'a'];
        }
        curr->isEndOfWord = true;
    }

    std::string getShortestPrefix(const std::string& word) {
        TrieNode* curr = root;
        std::string prefix = "";
        for (char c : word) {
            if (!curr->children[c - 'a']) break;
            prefix += c;
            curr = curr->children[c - 'a'];
            if (curr->isEndOfWord) return prefix;
        }
        return word;
    }

public:
    std::string replaceWords(std::vector<std::string>& dictionary, std::string sentence) {
        for (const std::string& word : dictionary) insert(word);
        
        std::istringstream ss(sentence);
        std::string word, res;
        bool first = true;
        
        while (ss >> word) {
            if (!first) res += " ";
            res += getShortestPrefix(word);
            first = false;
        }
        return res;
    }
};
