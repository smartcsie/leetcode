/**
 * 題目：1431. Kids With the Greatest Number of Candies (擁有最多糖果的孩子)
 * 難度：簡單 (Easy)
 * 描述：判斷每個小孩加上額外糖果後，是否為擁有最多糖果的人。
 * * 時間複雜度：O(N) - 掃描兩次陣列（一次找最大值，一次比較）。
 * 空間複雜度：O(1) - 不計入回傳的結果陣列空間。
 * * 設計思路：
 * 將題目要求的 `candies[i] + extraCandies >= max`
 * 改寫為 `candies[i] >= max - extraCandies`。
 * 這樣只需要做一次減法，減少了迴圈內每次都要做加法的開銷。
 */

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // 找到目前的糖果最大值
        int max_candies = *max_element(candies.begin(), candies.end());
        
        // 設定比較的門檻值
        int threshold = max_candies - extraCandies;
        
        vector<bool> res;
        res.reserve(candies.size()); // 預留空間優化
        
        for (int candy : candies) {
            // 若該小孩原有的糖果大於等於門檻值，則加上額外糖果後必為最大
            res.push_back(candy >= threshold);
        }
        
        return res;
    }
};
