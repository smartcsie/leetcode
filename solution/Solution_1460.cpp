/**
 * 題目：1460. Make Two Arrays Equal by Reversing Subarrays
 * 難度：簡單 (Easy)
 * 描述：判斷兩個長度相同的陣列是否能透過反轉子陣列變得完全相等。
 * * 時間複雜度：O(N) - N 為陣列長度。
 * 空間複雜度：O(K) - K 為數值的取值範圍（題目定義為 1000）。
 * * 優化思路：
 * 1. 變位詞性質：只要兩個陣列的元素分佈完全一致，就一定能透過反轉轉換。
 * 2. 提前退出：在統計過程中若發現頻率小於 0，可直接判斷不相等。
 */

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> seen(1001, 0);
        for(int i = 0 ; i < target.size(); i++) {
            seen[target[i]]++;
            seen[arr[i]]--;
        }
        for(const int& num : seen) {
            if(num != 0) return false;
        }
        return true;
    }
};
