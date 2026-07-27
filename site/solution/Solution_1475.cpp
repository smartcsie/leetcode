/**
 * 題目：1475. Final Prices With a Special Discount in a Shop (商品折扣後的最終價格)
 * 難度：簡單 (Easy)
 * 描述：每個商品價格減去其右側第一個小於等於它的價格（折扣）。
 * * 時間複雜度：O(N) - 每個價格最多進出 Stack 一次。
 * 空間複雜度：O(N) - Stack 儲存價格。
 */

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st; // 維護一個單調遞增的堆疊
        
        // 從後往前遍歷，找到右側第一個小於等於自己的值
        for (int i = prices.size() - 1; i >= 0; --i) {
            int currentPrice = prices[i];
            
            // 將所有大於當前價格的元素移除，因為它們不可能是當前的折扣
            while (!st.empty() && st.top() > currentPrice) {
                st.pop();
            }
            
            // 如果堆疊不為空，代表找到了第一個小於等於當前的價格
            if (!st.empty()) {
                prices[i] -= st.top();
            }
            
            // 將當前價格推入堆疊，作為之後元素的潛在折扣
            st.push(currentPrice);
        }
        
        return prices;
    }
};
