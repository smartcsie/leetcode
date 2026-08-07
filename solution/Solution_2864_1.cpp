class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        if(s.back() == '0') {
            int right = s.size() -1;
            while(right >=0 && s[right] == '0') right--;
            if(right >= 0) swap(s[right], s[s.size() -1]);
        }
        for(int i = 0, j = 0; i < s.size() -1 && j < s.size() -1 ; i++) {
                if(s[i] == '1') swap(s[i],s[j++]);
        }
        return s;
    }
};