/**
 * 題目：2678. Number of Senior Citizens (老年人的數目)
 * 難度：簡單 (Easy)
 * 描述：每個字串 `details` 長度為 15，其中索引 [11, 12] 表示年齡。計算年齡嚴格大於 60 的人數。
 * 
 * 時間複雜度：O(n) - 其中 n 為 details 陣列的大小。
 * 空間複雜度：O(1) - 僅使用整數變數進行計數。
 * 
 * 解法思路：
 * 1. 根據題意，每個詳細資訊的格式是固定的。
 * 2. 字串索引 [11, 12] 的字元分別代表十位數與個位數。
 * 3. 將字元轉換為數字：`s[i] - '0'`。
 * 4. 將數值組合為年齡：`(十位數 * 10) + 個位數`，並判斷是否大於 60。
 */

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(const string& s : details) {
            int age =(s[11] - '0') * 10 + (s[12] - '0');
            if(age > 60) count++;
        }
        return count;
    }
};
