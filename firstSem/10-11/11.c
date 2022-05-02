#include <stdio.h>

int main() {
    char cur, prev;
    while (cur != EOF) {
        cur = getchar();
        if (cur == '\n' && prev != ',' && prev != '.' && prev != ':' && prev != ';' && prev != '!' && prev != '?' && prev != '-') printf("%c", ' ');
        else printf("%c", cur);
        prev = cur;
    }
    return 0;
}
