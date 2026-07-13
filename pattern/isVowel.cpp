bool isVowel(char c) {
    static const bool lookup[256] = {
        ['a'] = true, ['e'] = true, ['i'] = true, ['o'] = true, ['u'] = true,
        ['A'] = true, ['E'] = true, ['I'] = true, ['O'] = true, ['U'] = true
    };
    return lookup[(unsigned char)c];
}
