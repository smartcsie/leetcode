/**
 * 題目：2485. Find the Pivot Integer
 * 難度：Easy
 * 描述：給定正整數 n，找出樞紐整數 x，使 1 到 x 的總和等於 x 到 n 的總和。
 *       存在則回傳 x，否則回傳 -1。題目保證答案若存在則唯一。
 *
 * 分類主題：binary-search-on-answer
 * 技巧：對答案二分搜尋, 等差級數求和公式, 左半和隨 x 遞增而右半和遞減所以具單調性
 *
 * 時間複雜度：O(log n)
 * 空間複雜度：O(1)
 *
 * 解法思路：對答案二分搜尋
 * 1. 候選答案是 1 ~ n 的整數，對每個 mid 計算兩側總和（等差級數公式）：
 *    - 左半 x = 1 + 2 + ... + mid = (1 + mid) * mid / 2
 *    - 右半 y = mid + (mid + 1) + ... + n = (mid + n) * (n - mid + 1) / 2
 * 2. 單調性：mid 變大時，左半多加一項（x 變大），右半少一項（y 變小），
 *    所以 x - y 隨 mid 嚴格遞增，可以用二分搜尋。
 * 3. 比較 x 與 y：
 *    - x == y：mid 就是樞紐整數，直接回傳。
 *    - x < y：左半太小，答案在更大的一邊，left = mid + 1。
 *    - x > y：左半太大，答案在更小的一邊，right = mid - 1。
 * 4. 搜尋範圍用完仍沒有 x == y，代表不存在，回傳 -1。
 * 5. 溢位檢查：我印象中 n <= 1000，總和最多約 50 萬，int 放得下。
 */
class Solution {
public:
    int pivotInteger(int n) {
        int left = 1;
        int right = n;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int x = (1 + mid) * mid / 2;            // 1 到 mid 的總和
            int y = (mid + n) * (n - mid + 1) / 2;  // mid 到 n 的總和
            if(x == y) {
                return mid;
            } else if(x < y){
                left = mid + 1;   // 左半較小，樞紐在右邊
            } else {
                right = mid - 1;  // 左半較大，樞紐在左邊
            }
        }
        return -1;
    }
};