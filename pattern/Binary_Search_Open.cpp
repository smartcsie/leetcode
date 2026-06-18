int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + ((right - left) / 2);
        if (nums[mid] == target) {
             return mid; // 找到目標
        } else if (nums[mid] > target) {
             right = mid; // 目標在左半區
        } else {
             left = mid + 1; // 目標在右半區
        }
    }
    return nums[left] == target ? left : -1;
}
