/**
 * 題目：1003. Check If Word Is Valid After Substitutions (檢查替換後的字串是否有效)
 * 難度：中等 (Medium)
 * 描述：一個字串從空字串開始，透過反覆在任意位置插入 "abc" 建構而成，稱為有效字串。
 *       給定字串 s，判斷它是否為有效字串。
 *
 * 時間複雜度：O(N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 1. 利用堆疊維護「未配對完成」的字元 (Stack for Pending Characters)：
 *    - 遇到 'a' 時直接推入堆疊，因為 'a' 永遠是每個 "abc" 區塊的開頭。
 * 2. 遇到 'b' 時檢查堆疊頂端 (Validate 'b')：
 *    - 只有堆疊非空且頂端恰好是 'a' 時，才能推入 'b'，
 *      否則代表這個 'b' 前面沒有對應的 'a'，直接回傳 false。
 * 3. 遇到 'c' 時檢查堆疊頂端 (Validate 'c')：
 *    - 只有堆疊非空且頂端恰好是 'b' 時才合法，此時將 'b' 與其下方的 'a' 一併彈出。
 * 4. 為何可以直接連續彈出兩次而不必再驗證第二次彈出的是 'a'：
 *    - 因為每次推入 'b' 之前，都已經驗證過當時堆疊頂端就是 'a'，
 *      且在該 'b' 被彈出之前，這個特定的 'a' 不可能被其他操作動到（只會從堆疊頂端存取），
 *      因此堆疊中 'b' 的正下方必定仍是當初那個 'a'，可以安全地連續彈出兩次。
 * 5. 最終驗證：
 *    - 走訪完整個字串後，若堆疊為空，代表所有字元都成功配對成完整的 "abc" 區塊，回傳 true。
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(const char&c : s) {
            if(c == 'a') {
                st.push(c);
            } else if(c == 'b') {
                if(st.empty() || st.top() != 'a') return false;
                st.push(c);
            } else {
                if(st.empty() || st.top() != 'b') return false;
                st.pop();
                st.pop();
            }
        }
        return st.empty();
    }
};
