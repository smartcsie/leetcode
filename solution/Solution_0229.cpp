/**
 * 題目：229. Majority Element II (多數元素 II)
 * 難度：中等 (Medium)
 * 描述：找出陣列中所有出現次數超過 ⌊n/3⌋ 的元素。
 * * 時間複雜度：O(N) - 兩次線性掃描。
 * 空間複雜度：O(1) - 僅使用常數空間。
 * * 設計思路：
 * 1. 投票階段：維護兩個候選人 `num1`, `num2`。當遇到與兩者皆不同的元素時，同時遞減計數器。
 * 2. 驗證階段：因為投票法產生的候選人不一定真的超過 n/3，必須再次掃描進行確認。
 */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num1 = 0, num2 = 0, cnt1 = 0, cnt2 = 0;

        // 第一階段：投票
        for (int num : nums) {
            if (num == num1) {
                cnt1++;
            } else if (num == num2) {
                cnt2++;
            } else if (cnt1 == 0) {
                num1 = num;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                num2 = num;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        // 第二階段：驗證 (必須執行，因為投票出來的候選人可能是虛假的)
        cnt1 = cnt2 = 0;
        for (int num : nums) {
            if (num == num1) cnt1++;
            else if (num == num2) cnt2++;
        }

        vector<int> res;
        if (cnt1 > n / 3) res.push_back(num1);
        if (cnt2 > n / 3) res.push_back(num2);

        return res;
    }
};
