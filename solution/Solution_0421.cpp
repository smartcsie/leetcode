/**
 * 題目：421. Maximum XOR of Two Numbers in an Array (陣列中兩個數字的最大異或值)
 * 難度：中等 (Medium)
 * 描述：給定一個整數陣列 nums，找出 nums[i] XOR nums[j] 的最大結果，其中 0 <= i <= j < n。
 *
 * 時間複雜度：O(N*L)
 * 空間複雜度：O(N)
 *
 * 解法思路：
 * 1. 逐位元建構前綴遮罩 (Prefix Masking)：
 *    - 從最高位元往低位元掃描，每次將該位元加入 prefixMask，取得目前所有數字的「前綴」（高位共同部分）。
 * 2. 貪婪嘗試候選答案 (Greedy Candidate)：
 *    - 假設答案在這一位元可以是 1（candidate = ans | 1 << i），檢查是否存在兩個前綴的 XOR 恰好等於 candidate。
 * 3. 集合查找驗證 (Hash Set Lookup)：
 *    - 若 prefix ^ candidate 存在於 prefixes 集合中，代表這一位元可以達成，將 ans 更新為 candidate。
 */

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int bits = bit_width(static_cast<unsigned int>(mx));
        int bitMask = 0;
        int ans = 0;
        for(int i = bits - 1; i >= 0; i--) {
            bitMask |= 1 << i;
            unordered_set<int> prefixs;
            for(const int& num : nums) {
                prefixs.insert(num & bitMask);
            }
            int candidate = ans | 1 << i;
            for(const int& prefix : prefixs) {
                //這裡原本是 存在兩數num1, num2 之prefix 有辦法
                // prefix1 ^ prefix2 == candidate(最佳) 則更新 ans prefix
                // 等價 prefixs.contains(prefix ^ candidate)
                if(prefixs.contains(prefix ^ candidate)) {
                    ans = candidate;
                    break;
                }
            }
        }
        return ans;
    }
};