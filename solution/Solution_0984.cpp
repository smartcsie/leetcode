/**
 * 題目：984. String Without AAA or BBB (不含 AAA 或 BBB 的字串)
 * 難度：中等 (Medium)
 * 描述：給定兩個整數 a 和 b，建構一個長度為 a+b 的字串，恰好包含 a 個 'a' 與
 *       b 個 'b'，且不能包含連續三個 'a'（"aaa"）或連續三個 'b'（"bbb"）。
 *       題目保證對於給定的 a、b，一定存在合法解。
 *
 * 時間複雜度：O(A + B) - 每次遞迴呼叫至少消耗掉 1 個字元額度，總遞迴深度與字串長度成正比。
 * 空間複雜度：O(A + B) - 遞迴呼叫堆疊的深度，加上字串拼接產生的中間字串。
 *
 * 解法思路：
 * 1. 邊界情況：其中一方已經用完 (Base Cases)：
 *    - 若 a 或 b 已經歸零，代表剩下的另一方可以安全地一次全部輸出
 *      （因為題目保證輸入一定有解，當其中一方歸零時，另一方必定不超過能安全輸出的範圍）。
 * 2. 兩者相等時，交替各放一個 (Equal Case)：
 *    - 當 a == b 時，直接放 "ab"，各自遞減 1，維持兩邊平衡地消耗。
 * 3. 貪婪策略：優先多用數量較多的那一方 (Greedy: Favor the Larger Count)：
 *    - 若 a > b，放入 "aab"（連續兩個 a 加一個 b），因為 a 比較多，
 *      這樣可以更快消耗掉多餘的 a，同時用 b 隔開避免出現三個連續 a。
 *    - 若 b > a，同理放入 "bba"。
 * 4. 為什麼放兩個而不是三個：
 *    - 每次最多放兩個相同字元（例如 "aa"），因為放第三個就會違反「不能連續三個」的限制，
 *      緊接著放一個對方的字元，確保連續相同字元的長度不超過 2。
 */
class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans;
        ans.reserve(a + b);
        while(a && b) {
            if(a > b) {
                ans.push_back('a'); ans.push_back('a'); ans.push_back('b');
                a -= 2 ; 
                b -= 1;
            } else if(a < b) {
                ans.push_back('b') ; ans.push_back('b'); ans.push_back('a');
                a -= 1 ; b -= 2;
            } else {
                ans.push_back('a') ; ans.push_back('b');
                a -= 1 ; b -= 1;
            }
        }
        while(a--)  ans.push_back('a');
        while(b--)  ans.push_back('b');
        return ans;
    }
};
