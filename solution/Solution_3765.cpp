/**
 * 題目：3765. Complete Prime Number
 * 難度：簡單 (Easy)
 * 描述：檢查一個數的所有前綴與後綴是否皆為質數。
 * * 優化重點：
 * 1. 質數判定優化：使用 6k +/- 1 規律減少迴圈次數。
 * 2. 子串提取：利用 std::to_string 與 std::stoi 簡化數位轉換邏輯。
 */

class Solution {
private:
    // 高效質數判定
    bool isPrime(int n) {
        if (n < 2) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }

public:
    bool completePrime(int num) {
        std::string s = std::to_string(num);
        int n = s.size();
        
        // 遍歷所有可能的長度 1 到 n
        for (int i = 1; i <= n; i++) {
            // 檢查前綴 (長度 i)
            int prefix = std::stoi(s.substr(0, i));
            if (!isPrime(prefix)) return false;
            
            // 檢查後綴 (長度 i)
            int suffix = std::stoi(s.substr(n - i, i));
            if (!isPrime(suffix)) return false;
        }
        
        return true;
    }
};
