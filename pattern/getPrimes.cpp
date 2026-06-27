vector<bool> getPrimes(int n) {
    bitset<n + 1> isPrime;
    isPrime.set();
    isPrime.reset(0);
    isPrime.reset(1);
    for(int p = 2; p *p <= n; p++) {
        if(isPrime[p]) {
            for(int i = p*p; i <= n; i += p) {
                isPrime.reset(i);;
            }
        }
    }
    return isPrime;
}
