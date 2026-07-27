/**
 * 題目：2177. Find Three Consecutive Integers That Sum to a Given Number (找到和為給定整數的三個連續整數)
 * 難度：中等 (Medium)
 * 描述：給定一個整數 num，回傳三個連續整數，其和等於 num；若不存在則回傳空陣列。
 * * 時間複雜度：O(1) - 僅包含基本的算術運算。
 * 空間複雜度：O(1) - 僅返回固定長度的陣列。
 * * 設計思路：
 * 設三個連續整數為 (x-1, x, x+1)，則其和為 3x。
 * 若 num % 3 != 0，則無法被 3 整除，回傳 {}。
 * 否則，中間數 x = num / 3。
 */

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        // 檢查 num 是否為 3 的倍數
        if (num % 3 != 0) {
            return {};
        }
        
        // 計算中間數
        long long mid = num / 3;
        
        // 直接返回結果
        return {mid - 1, mid, mid + 1};
    }
};
