#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const char MC_CHARS[] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', ',',
};
#define MC_CHARS_COUNT (sizeof(MC_CHARS) / sizeof(MC_CHARS[0]))

const char *const MC_TABLE[] = {
    ['A'] = ".-",     ['B'] = "-...",   ['C'] = "-.-.",  ['D'] = "-..",
    ['E'] = ".",      ['F'] = "..-.",   ['G'] = "--.",   ['H'] = "....",
    ['I'] = "..",     ['J'] = ".---",   ['K'] = "-.-",   ['L'] = ".-..",
    ['M'] = "--",     ['N'] = "-.",     ['O'] = "---",   ['P'] = ".--.",
    ['Q'] = "--.-",   ['R'] = ".-.",    ['S'] = "...",   ['T'] = "-",
    ['U'] = "..-",    ['V'] = "...-",   ['W'] = ".--",   ['X'] = "-..-",
    ['Y'] = "-.--",   ['Z'] = "--..",   ['0'] = "-----", ['1'] = ".----",
    ['2'] = "..---",  ['3'] = "...--",  ['4'] = "....-", ['5'] = ".....",
    ['6'] = "-....",  ['7'] = "--...",  ['8'] = "---..", ['9'] = "----.",
    ['.'] = ".-.-.-", [','] = "--..--",
};

int32_t rand_range(int32_t lower, int32_t upper) {
    assert(lower < upper);
    return (upper - lower) * (rand() / (double)RAND_MAX) + lower;
}

bool expect_user_input(const char *expected) {
    char x;

    while (*expected) {
        x = getchar();

        if (x == '\n') return false;
        if (x != *expected) break;

        expected++;
    }
    // end of expected has been reached

    if ((x = getchar()) != '\n') {
        while (x != '\n') x = getchar();
        return false;
    }

    return true;
}

bool test_char(char alpha) {
    const char *expected = MC_TABLE[alpha];
    printf("%c: ", alpha);

    bool correct = expect_user_input(expected);
    if (correct) {
        printf("Correct!\n");
    } else {
        printf("Incorrect: %s\n", expected);
    }
    return correct;
}

int main(void) {
    while (true) {
        size_t i = rand_range(0, MC_CHARS_COUNT);
        char alpha = MC_CHARS[i];

        test_char(alpha);
    }
    return 0;
}
