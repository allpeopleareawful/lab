//13.c

#include <stdio.h>
#include "headers/set.h"
#include "headers/word.h"

int main() {
    char c;
    char input[LEN] = {'\0'}, example_set[N * 2], set[N * 2], ans[LEN] = {'\0'};
    int len, maxlen = 0, first = 1, i;

    while (c != EOF) {
        i = 0;
        Clear(input);
        while (((c = getchar()) != ' ') && (c != '\0') && (c != '\n')) {
            if (Letter(c)) input[i] = c;
            else break;
            ++i;
        }
        if (first) {
            first = 0;
            CreateSet(input, example_set);
            continue;
        }
        len = Len(input);
        CreateSet(input, set);
        if ((len > maxlen) && (IncludeSet(set, example_set))) {
            Copy(input, ans);
            maxlen = len;
        }
    }
    printf("%s\n", ans);
    return 0;
}
