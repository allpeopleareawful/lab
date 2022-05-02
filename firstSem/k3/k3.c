#include <math.h>
#include <stdio.h>

int main() {
    double S, p, eps = 1, x;
    float a = 0, b = 1, h = (b - a) / 100;
    int n;
    while (1 + eps > 1)
        eps /= 1.1;
    printf("╓┈┈┈┈┈┈┈┈┈┈┈┈┈Machine  Epsilon in HP Omen on Ryzen 7 5800h = %.40f┈┈┈┈┈┈┈┈┈┈┈┈┈╖\n", eps);
    printf("╟┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈Table of Taylor series and standard function values for f = sin²(x)┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈╢\n");
    printf("╠══════════════════╦═══════════════════════════════════════╦═════════════════════════════════╦══════════════════════╣\n");
    printf("║        x         ║ Partial sum of the series for sin²(x) ║           sin²(x) value         ║ Number of iterations ║\n");
    printf("╠══════════════════╬═══════════════════════════════════════╬═════════════════════════════════╬══════════════════════╣\n");
    for (x = 0; x <= b+0.001; x+=h) {
        p = (2 * x * x) / 2;
        n = 1;
        S = p;
        while (fabs(p) > eps) {
            ++n;
            p = (-p * 4 * x * x) / ((2 * n) * (2 * n - 1));
            S += p;
        }
        if (n < 10)
            printf("║       %.2f       ║         %.20f        ║      %.20f     ║          %d           ║\n", x, S,
                   sin(x) * sin(x),
                   n);
        else
            printf("║       %.2f       ║         %.20f        ║      %.20f     ║          %d          ║\n", x, S,
                   sin(x) * sin(x), n);
    }
    printf("╚══════════════════╩═══════════════════════════════════════╩═════════════════════════════════╩══════════════════════╝\n");
    return 0;
}

