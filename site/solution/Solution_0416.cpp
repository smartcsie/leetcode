/**
 * 題目：416. Partition Equal Subset Sum (分割等和子集)
 * 難度：中等 (Medium)
 * 描述：判斷陣列是否可分割為兩個和相等的子集。
 * * 時間複雜度：O(N * S / W) - N 為陣列長度，S 為總和，W 為系統字長（通常為 64）。
 * 空間複雜度：O(S / W) - bitset 佔用的記憶體空間。
 * * 優化思路：
 * 1. 剪枝：若總和為奇數，直接回傳 false。
 * 2. Bitset DP：將每個數字視為位元位移運算，bits |= (bits << num) 表示「若原本能組成某和，加上 num 後亦能組成該和」。
 */

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        // 奇數總和無法均分
        if (sum % 2 != 0) return false;
        
        int target = sum >> 1;
        
        // 檢查是否有單個元素超過目標值（額外剪枝）
        // 這裡 bitset 大小應設定為 target + 1，節省空間
        bitset<10001> bits;
        bits[0] = 1; // 初始狀態：總和為 0 是可達成的
        
        for (const int& num : nums) {
            // 位元左移代表加上 num，位元或運算合併狀態
            bits |= (bits << num);
            
            // 可選優化：若已經能組成目標，提前中斷
            if (bits[target]) return true;
        }
        
        return bits[target];
    }
};
