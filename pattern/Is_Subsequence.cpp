bool isSubsequence(const string& s, const string& t) {
    int i = 0, n = s.size();
    for (char c : t) {
        if (s[i] == c) {
            i++;
            if (i == n) return true; 
        }
    }
    return false;
}
