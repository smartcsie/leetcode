/**
 * 題目：405. Convert a Number to Hexadecimal
 * 描述：將一個整數轉換為十六進位字串。負數必須以二補數 (Two's Complement) 表示。
 * 
 * 解法思路：
 * 1. 使用 unsigned int 處理：將輸入強制轉型為 unsigned int，這樣可以確保負數在進行位元運算時，
 *    右移 (>>) 為邏輯右移（補 0），而不會觸發負數的算術右移（補 1）導致死迴圈。
 * 2. 位元遮罩 (Bitmask)：每次取末 4 位元 (`num & 0xf`) 對應到十六進位的一個字元。
 * 3. 循環處理：不斷將數字右移 4 位 (`num >>= 4`)，直到數字變為 0。
 */

class Solution {
public:
    std::string toHex(int num) {
        if (num == 0) return "0";
        
        // 轉為無號數以正確處理二補數及避免右移補 1
        unsigned int n = static_cast<unsigned int>(num);
        
        // 十六進位對照表
        constexpr char hex[] = "0123456789abcdef";
        std::string ans;
        
        while (n != 0) {
            // 取最後 4 個 bits 作為 index
            ans.push_back(hex[n & 0xf]);
            n >>= 4;
        }
        
        // 因為是從低位取到高位，最後需要反轉
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
