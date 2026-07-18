/**
 * 題目：121. Best Time to Buy and Sell Stock
 * 描述：在給定的價格陣列中，找出一筆買賣的最大利潤。
 * 
 * 解法思路 (狀態機 DP)：
 * 1. 定義兩個變數來記錄狀態：
 *    - holdOne: 持有一支股票時的最大利潤（由於只能買一次，所以買入價即為負的 cost）。
 *    - sellOne: 賣出一支股票後的最大利潤（即為最終利潤）。
 * 2. 遍歷價格：
 *    - 更新 sellOne: 比較「維持原樣」或「在今天賣掉」。
 *    - 更新 holdOne: 比較「維持原樣」或「在今天買入」。
 */

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int sellOne = 0;             // 初始賣出利潤為 0
        int holdOne = INT_MIN;       // 初始持有成本設為極小值
        for (const int price : prices) {
            // 賣出股票：當前利潤與(持有的股票賣掉)取最大值
            sellOne = std::max(sellOne, holdOne + price);
            // 持有股票：當前持股與(今天買入)取最大值
            // 因為是第一次買入，所以直接用 -price
            holdOne = std::max(holdOne, -price);
        }
        return sellOne;
    }
};
