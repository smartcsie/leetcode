/**
 * 題目：349. Intersection of Two Arrays
 * 難度：簡單 (Easy)
 * 描述：找出兩個陣列的交集，結果中的每個元素只能出現一次。
 * 時間複雜度：O(N+M)
 * 空間複雜度：O(N)

 */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        bitset<1001> bits1, bits2;
        for(const int& x : nums1) bits1.set(x);
        for(const int& x : nums2) bits2.set(x);
        vector<int> ans;
        for(int x = 0; x <= 1000; x++) {
            if(bits1[x] && bits2[x]) ans.push_back(x);
        }
        return ans;
    }
};
    }
};