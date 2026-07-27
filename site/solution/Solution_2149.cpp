/**
 * 題目：2149. Rearrange Array Elements by Sign (按符號重新排列陣列元素)
 * 難度：中等 (Medium)
 * 描述：將正數與負數交替排列，維持相對順序，且保證陣列元素數量相等且不為 0。
 * * 時間複雜度：O(N) - 僅遍歷輸入陣列一次。
 * 空間複雜度：O(N) - 用於儲存重排後的結果。
 */

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        // 預分配空間，避免推入過程中發生記憶體搬移
        vector<int> res(n);
        
        // 使用雙指標分別指向正數與負數的下一個填入位置
        int posIdx = 0; // 正數從 index 0 開始
        int negIdx = 1; // 負數從 index 1 開始
        
        for (const int num : nums) {
            if (num > 0) {
                res[posIdx] = num;
                posIdx += 2;
            } else {
                res[negIdx] = num;
                negIdx += 2;
            }
        }
        
        return res;
    }
};
