/**
 * 題目：1491. Average Salary Excluding the Minimum and Maximum Salary
 * 描述：給你一個整數陣列 salary，代表員工的薪資，請你返回去掉最低薪資與最高薪資之後，
 *       其餘員工薪資的平均值。
 * 
 * 解法思路：
 * 1. 取得陣列長度 n。
 * 2. 使用 `std::accumulate` 計算所有薪資的總和（初始值給 0.0 以確保浮點數除法）。
 * 3. 使用現代 C++ 的 `std::minmax_element` 同時找出陣列中的最小值與最大值迭代器。
 * 4. 總和減去最小值與最大值，再除以 `n - 2`（排除極端值後的剩餘人數）即為平均薪資。
 */

class Solution {
public:
    double average(std::vector<int>& salary) {
        int n = salary.size();
        
        // 1. 計算所有薪資總和（型態使用 double 避免整數除法誤差）
        double sum = std::accumulate(salary.begin(), salary.end(), 0.0);
        
        // 2. 同時找出最小值與最大值的迭代器
        auto [minIt, maxIt] = std::minmax_element(salary.begin(), salary.end());
        
        // 3. 扣除最少與最多薪資後，計算平均值
        return (sum - *minIt - *maxIt) / (n - 2);
    }
};
