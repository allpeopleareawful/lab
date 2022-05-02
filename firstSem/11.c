#include <stdio.h>	
 
#define next '\n'
#define blanc ' '
#define point '.'
#define comma ','
#define question '?'
 
int main() {
    int i = 0, j, flag = 0;
    char word[63] = {'\0'};
    char cur, ruc;
    while (cur != EOF) {
        begin:
        cur = getchar();
        if (cur == blanc || cur == point || cur == comma || cur == question) {
            flag = 1;
            clear:
            for (j = 0; j <= i; j++) {
                word[j] = '\0';
            }
            i = 0;
            goto begin;
        }
        if ((cur == next)&&(flag==0)) {
            ruc = getchar();
            if (ruc != EOF) {
                printf("%s", word);
                printf("%c", blanc);
                for (j = 0; j <= i; j++) {
                    word[j] = '\0';
                }
                word[0] = ruc;
                i = 1;
                while (cur != EOF) {
                    cur = getchar();
                    if (cur == blanc || cur == next || cur == point || cur == comma || cur == question) {
                        printf("%s\n", word);
                        goto clear;
                    }
                    word[i] = cur;
                    i++;
                }
            }
            //break;
        }
        word[i] = cur;
        i++;
        flag = 0;
    }
    return 0;
}
