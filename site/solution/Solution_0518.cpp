/**
 * 題目：518. Coin Change II (零錢兌換 II)
 * 難度：中等 (Medium)
 * 描述：找出使用不同面額硬幣組成金額 amount 的組合總數。
 * * 時間複雜度：O(N * A) - N 為硬幣數量，A 為金額大小。
 * 空間複雜度：O(A) - 使用一維陣列優化空間。
 * * 優化思路：
 * 1. 完全背包模型：每個硬幣可選取無限次，故內層迴圈必須「正序」遍歷 (i = coin 到 amount)。
 * 2. 組合計數特性：外層遍歷硬幣、內層遍歷金額，避免了 {1, 2} 和 {2, 1} 被重複計數。
 */

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // 使用 unsigned int 以擴大正整數儲存範圍
        vector<unsigned int> dp(amount + 1, 0);
        
        // 基礎情況：組成金額 0 的方法只有一種（什麼硬幣都不選）
        dp[0] = 1;
        
        // 遍歷硬幣：確保每次加入一種新硬幣時，金額 i 的組合數更新皆基於已計算出的狀態
        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                // 狀態轉移：組成金額 i 的組合數 = 扣除當前硬幣後的組合數累加
                dp[i] += dp[i - coin];
            }
        }
        
        return static_cast<int>(dp[amount]);
    }
};
