/**
 * 題目：3551. Minimum Swaps to Sort by Digit Sum
 * 難度：中等 (Medium)
 * 描述：根據元素的「數位總和」進行排序，計算最少需要的元素交換次數。
 * * 優化重點：
 * 1. 循環分解：利用 N - cycles 計算總交換次數。
 * 2. 映射建立：使用哈希表快速定位元素排序後的目標位置。
 */

class Solution {
private:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int minSwaps(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++) {
            pairs[i] = {digitSum(nums[i]), nums[i]};
        }

        // 根據數位和排序 (若數位和相同，std::pair 預設會根據第二個值排序)
        std::sort(pairs.begin(), pairs.end());

        // 建立映射：value -> target_index
        std::unordered_map<int, int> target_pos;
        for (int i = 0; i < n; i++) {
            target_pos[pairs[i].second] = i;
        }

        // 循環分解計算
        std::vector<bool> seen(n, false);
        int cycles = 0;
        for (int i = 0; i < n; i++) {
            if (!seen[i]) {
                cycles++;
                int curr = i;
                while (!seen[curr]) {
                    seen[curr] = true;
                    // 將當前位置的元素，跳轉至其排序後應在的目標位置
                    curr = target_pos[nums[curr]];
                }
            }
        }
        
        // 總交換次數 = N - 循環數量
        return n - cycles;
    }
};
