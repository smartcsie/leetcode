static bool isVowel(char c) {
    int lower = c | 0x20;
    return ((static_cast<int>(lower - '`') << 1) & 2130466) > 0;
}
