/**
 * 題目：43. Multiply Strings
 * 難度：中等 (Medium)
 * 描述：以字串形式回傳兩個非負整數的乘積。
 * * 優化重點：
 * 1. 空間預分配：結果陣列大小固定為 M + N，避免動態擴容。
 * 2. 位置對應：巧妙利用 i + j 與 i + j + 1 定位乘積影響位置。
 */

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int m = num1.size(), n = num2.size();
        std::vector<int> products(m + n, 0);
        
        // 從個位數開始反向相乘
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + products[p2];
                
                products[p2] = sum % 10;   // 當前位數
                products[p1] += sum / 10; // 進位至高位
            }
        }
        
        // 將陣列轉回字串，跳過前導零
        std::string res;
        for (int p : products) {
            if (!(res.empty() && p == 0)) {
                res.push_back(p + '0');
            }
        }
        
        return res.empty() ? "0" : res;
    }
};
