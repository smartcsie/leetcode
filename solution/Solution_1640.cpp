/**
 * 題目：1640. Check Array Formation Through Concatenation
 * 難度：簡單 (Easy)
 * 描述：檢查 arr 是否可以透過串聯 pieces 中的陣列組成。
 * * 優化重點：
 * 1. 移除額外的 `res` 向量：直接掃描 `arr` 並與映射表中的 `piece` 比對，空間複雜度更低。
 * 2. 指標操作：使用 index 變數直接在 `arr` 上移動，避免不必要的資料複製。
 */

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, vector<int>> map;
        map.reserve(pieces.size());
        for(const vector<int>& piece : pieces) {
            map[piece[0]] = piece;
        }
        int i = 0;
        int n = static_cast<int>(arr.size());

        while(i < n) {
            if(!map.contains(arr[i])) return false;
            vector<int> piece = map[arr[i]];
            for (int val : piece) {
                if(i > n || arr[i] != val) return false;
                i++;
            }
        }
        return true;
    }
};
