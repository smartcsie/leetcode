/**
 * 題目：2491. Divide Players Into Teams of Equal Skill
 * 描述：將玩家分成每組 2 人的隊伍，使每組技能總和相等。
 *       若能分成功，返回所有隊伍「化學反應（相乘）」的總和；否則返回 -1。
 * 
 * 解法思路：
 * 1. 將 skill 陣列進行由小到大的排序。
 * 2. 根據貪婪法則，總和相等的最佳配對方式一定是「最左邊（最小）與最右邊（最大）」配對。
 * 3. 確立目標值 target = skill[0] + skill[n - 1]。
 * 4. 使用雙指標 (left, right) 分別從頭尾向中間掃描：
 *    - 若任一組的相加不等於 target，代表無法平分，直接回傳 -1。
 *    - 若相等，則將該組的乘積累加至總化學反應中。
 * 5. 掃描完畢後回傳總化學反應值。
 */

class Solution {
public:
    long long dividePlayers(std::vector<int>& skill) {
        // 1. 將技能陣列排序
        std::sort(skill.begin(), skill.end());
        
        int n = skill.size();
        int target = skill[0] + skill[n - 1]; // 每一隊必須相加等於這個目標值
        int left = 0, right = n - 1;
        long long sum = 0;
        
        // 2. 雙指標向內檢查並計算化學反應
        while (left < right) {
            if (skill[left] + skill[right] != target) {
                return -1; // 總和不匹配，無法組出均等隊伍
            }
            
            // 3. 累加該隊的化學反應（相乘），注意轉型避免整數溢位
            sum += (long long)skill[left] * skill[right];
            
            left++;
            right--;
        }
        
        return sum;
    }
};
