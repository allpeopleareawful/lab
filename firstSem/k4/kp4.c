#include <stdio.h>
#include "funcs.h"
 
int main() {
    printf("f1 = 2 * x * sin(x) - cos(x) = 0\nf2 = 0.5 + atan(sqrt(x)) - x = 0\nf3 = 4 * cos(x * sin(x)) + exp(x) + 5 * x = 0\n\n");
    printf("f1 dichotomy = %.5f\n", dichotomy(f1, 0.4, 1.));
    printf("f1 iterations = %.5f\n", iteration(F1, 0.4, 1.));
    printf("f1 tangent = %.5f\n", tangent(f1, Fp1, 0.4, 1.));
    printf("f1 chord = %.5f\n\n", chord(f1, 0.4, 1.));
    printf("f2 dichotomy = %.5f\n", dichotomy(f2, 1., 1.5));
    printf("f2 iterations = %.5f\n", iteration(F2, 1., 1.5));
    printf("f2 tangent = %.5f\n", tangent(f2, Fp2, 1., 1.5));
    printf("f2 chord = %.5f\n\n", chord(f2, 1., 1.5));
    printf("f3 dichotomy = %.5f\n", dichotomy(f3, -1., 0.5));
    printf("f3 iterations = %.5f\n", iteration(F3, -1., 0.5));
    printf("f3 tangent = %.5f\n", tangent(f3, Fp3, -1., 0.5));
    printf("f3 chord = %.5f\n\n", chord(f3, -1., 0.5));
    return 0;
}
