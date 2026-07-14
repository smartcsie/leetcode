static bool isVowel(char c) {
    int lower = c | 0x20;
    return (0x104111 >> (c - 'a')) & 1;
}
