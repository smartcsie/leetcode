// 題目：Smallest Absent Positive Greater Than Average（題號請自行補上）
// 難度：Easy
// 時間複雜度：O(n + V)，V = 值域大小（約 100）
// 空間複雜度：O(1)（固定 102 bits 的 bitset）
// 分類主題：array / hash-table / math
// 技巧：bitset 當存在表（值域小）、整數除法求「剛好大於平均」的起點

class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        // 題目限制 -100 <= nums[i] <= 100，只有正數才可能擋住答案，
        // seen[v] = 1 表示正數 v 出現在 nums 中；多開到 102 讓 index 101 合法
        bitset<102> seen;
        int sum = 0;
        int n = nums.size();
        for(const int& x : nums) {
            // 負數和 0 不需要記錄；而且 bitset 用負數當索引會轉成很大的無號數，
            // set() 會丟出 out_of_range 例外，所以一定要先過濾
            if(x > 0) seen.set(x);
            sum += x;
        }

        // 答案必須是「正整數」且「嚴格大於平均值」，所以從下列起點往上找：
        //   sum / n + 1：整數除法取商，再 + 1 就是「大於平均的最小整數」
        //     例：平均 2.5 -> 2 + 1 = 3；平均 3（整除）-> 3 + 1 = 4（要嚴格大於）
        //     平均為負數時（C++ 除法往 0 截斷），結果必然 <= 1，會被下面的 max 修正
        //   max(1, ...)：保證答案是正整數
        // 往上找第一個沒出現在 nums 的數字
        for(int x = max(1, (sum / n) + 1); x <= 101; x++) {
            if(!seen[x]) return x;
        }

        // 平均值最大是 100，起點最大是 101，而 nums 裡不可能有 101，
        // 所以迴圈最多到 101 一定會回傳，這行不會被執行到
        return -1;
    }
};