static bool isVowel(char c) {
    int lower = c | 0x20;
    return (2130466 >> (c - '`')) & 1;
}
