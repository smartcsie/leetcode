class Solution {
public:
    int hammingDistance(int x, int y) {
        int xorVal = x ^ y;
        int count = 0;
        while (xorVal) {
            xorVal &= (xorVal - 1);  // 每次消除最低位的 1
            count++;
        }
        return count;
    }
};