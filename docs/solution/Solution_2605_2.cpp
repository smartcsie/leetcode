class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        bitset<10> bits1;
        bitset<10> bits2;
        for(const int& num: nums1) bits1.set(num);
        for(const int& num: nums2) bits2.set(num);
        bitset<10> bits3 = bits1 & bits2;
        if(bits3.count()) {
            return static_cast<int>(bits3._Find_first());
        }
        int min1 = static_cast<int>(bits1._Find_first());
        int min2 = static_cast<int>(bits2._Find_first());
        return min1 > min2 ? min2 * 10 + min1 : min1 * 10 + min2;

    }
};
