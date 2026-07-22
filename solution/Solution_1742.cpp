/**
 * 題目：1742. Maximum Number of Balls in a Box
 * 描述：給你 lowLimit 與 highLimit，將編號在此範圍內的球放入各位數字和對應的箱子中，
 *       返回擁有最多球的箱子裡面的球數。
 * 
 * 解法思路：
 * 1. 根據題意，球的最大編號不超過 10^5（LeetCode 1742 的測資範圍），
 *    因此各位數字和的最大值不會超過 9 + 9 + 9 + 9 + 9 = 45。
 * 2. 宣告一個大小為 46 的 `std::vector<int> counts(46, 0)` 作為箱子計數器。
 * 3. 走訪從 lowLimit 到 highLimit 的每一個球編號 i：
 *    - 利用迴圈計算 i 的各位數字總和 num。
 *    - 將對應箱子的計數器加 1：`counts[num]++`。
 * 4. 走訪完畢後，使用 `std::max_element` 找出 counts 陣列中的最大值並回傳。
 */

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        // 根據最大可能數字（10^5 內），數位和最大為 45，故宣告大小 46 的陣列
        std::vector<int> counts(46, 0);
        
        for (int i = lowLimit; i <= highLimit; ++i) {
            int n = i;
            int num = 0;
            
            // 計算當前編號的各位數字總和
            while (n > 0) {
                num += n % 10;
                n /= 10;
            }
            
            // 將球放入對應的箱子中
            counts[num]++;
        }
        
        // 返回所有箱子中的最大球數
        return *std::max_element(counts.begin(), counts.end());
    }
};
