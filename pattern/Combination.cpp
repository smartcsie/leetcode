long C(int n, int k) {
    if(k == 0 || k == n) return 1;
    long res = 1;
    if (k > n / 2) k = n - k;
    for(int i = 1; i <= k; i++) {
        res = res * (n - i + 1) / i;
    }
    return res;
}
