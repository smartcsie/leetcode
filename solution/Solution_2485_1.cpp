class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1) return 1;
        for(int x = n / 2 ; x < n; x++) {
            if( (1 + x) * x / 2 == (x + n) * (n - x + 1) / 2 ) return x; 
        }
        return -1;
    }
};