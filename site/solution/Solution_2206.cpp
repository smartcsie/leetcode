/**
 * 題目：2206. Divide Array Into Equal Pairs (將陣列分成完全相等的數對)
 * 難度：簡單 (Easy)
 * 描述：給你一個包含 2n 個整數的陣列 nums。你需要將其分成 n 個數對，使得每個數對中的兩個數字相等。
 *      若能成功達成，回傳 true；否則回傳 false。
 * 
 * 時間複雜度：O(n) - 需要遍歷一次 nums 陣列進行統計，隨後遍歷一次計數陣列。
 * 空間複雜度：O(1) - 使用了固定大小為 501 的計數陣列（與輸入規模 n 無關）。
 * 
 * 解法思路：
 * 1. 核心邏輯：若一個數字可以全部配成相等數對，則該數字在陣列中出現的總次數必須是「偶數」。
 * 2. 由於題目限制數字範圍在 1 到 500 之間，我們可以使用一個長度為 501 的陣列來記錄每個數字出現的次數。
 * 3. 遍歷計數陣列，若發現任何數字出現的次數為奇數，則無法完成配對，回傳 false。
 */

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        short count[501] = {0};
        for(int num : nums) {
            count[num]++;
        }
        for(int i = 0 ;i < 501; i++) {
            if(count[i] % 2 != 0) return false;
        }
        return true;
    }
};
