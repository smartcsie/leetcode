int gcd(int a, int b) {
    return b == 0 ? abs(a) : gcd(b, a % b);
}
