#include <stdio.h>

int main() {
    long num, even = 0, odd = 0, e_count = 1, o_count = 1;
    int tmp;
    printf("Input number = ");
    scanf("%ld", &num);
    while (num) {
        tmp = num % 10;
        if (tmp % 2 == 0) {
            even += tmp * e_count;
            e_count *= 10;
        } else {
            odd += tmp * o_count;
            o_count *= 10;
        }
        num /= 10;
    }
    printf("even = %ld\n odd = %ld\n op = %ld\n", even, odd, even * odd);
    return 0;
}
