int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
        
    // 區間閉合 [left, right]，因此使用 <=
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (nums[mid] == target) {
             return mid; // 找到目標
        } else if (nums[mid] > target) {
             right = mid - 1; // 目標在左半區
        } else {
                left = mid + 1; // 目標在右半區
        }
    }
    return -1; // 找不到
}
