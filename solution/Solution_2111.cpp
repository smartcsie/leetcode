/**
 * 題目：2111. Minimum Operations to Make the Array K-Increasing
 * 難度：困難 (Hard)
 * 分類主題：greedy-optimal-partitioning
 * 描述：給定陣列 arr 和整數 k，如果對每個 i，arr[i] <= arr[i+k]，
 * 就稱這個陣列是「K-遞增」的。每次操作可以把某個元素改成任意值，求
 * 最少操作次數讓陣列變成 K-遞增。
 *
 * 時間複雜度：O(N log N)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * （這題的關鍵拆解：K-遞增的條件其實是把陣列拆成 k 條獨立的子序列，
 * 各自都要非遞減，是一種「分割問題」的變形——把大問題切成 k 個互不
 * 干擾的子問題，各自求解再加總）：
 * 1. **關鍵觀察**：條件 arr[i] <= arr[i+k] 只連結「間隔 k」的位置，
 *    完全不會跨越到「餘數不同」的位置。也就是說，把陣列按照索引
 *    對 k 取餘數分組（餘數 0 的一組：arr[0], arr[k], arr[2k]...；
 *    餘數 1 的一組：arr[1], arr[k+1]...；以此類推），k 個分組彼此
 *    獨立，只要每組內部自己是非遞減的，整個陣列就是 K-遞增的。
 * 2. 對每一組，問題就退化成：「最少改幾個元素，讓這個子序列變成
 *    非遞減」——這等價於「子序列長度 - 最長不遞減子序列（LNDS）的
 *    長度」（保留 LNDS 那些元素不動，其餘的都改成能接上的值）。
 * 3. 用標準的 patience sorting 技巧求 LNDS 長度（維護 tails 陣列，
 *    這裡允許相等所以用 upper_bound，跟之前 1964 題找非遞減 LIS
 *    是同一招）：`upper_bound` 找到第一個「大於」目前元素的位置，
 *    push_back 或替換掉。
 * 4. 把 k 組各自算出的「需要修改的元素數」加總，就是答案。
 */
class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        int totalOps = 0;
        for (int r = 0; r < k; ++r) {
            vector<int> seq;
            for (int i = r; i < n; i += k) seq.push_back(arr[i]);

            vector<int> tails;
            for (int x : seq) {
                int idx = upper_bound(tails.begin(), tails.end(), x) - tails.begin();
                if (idx == (int)tails.size()) tails.push_back(x);
                else tails[idx] = x;
            }
            totalOps += (int)seq.size() - (int)tails.size();
        }
        return totalOps;
    }
};
