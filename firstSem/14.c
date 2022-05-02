#include <stdio.h>

int main() {
    int a[9][9], n, i, j, k, di = -1, dj = -1;;
    printf(" Input size of matrix = ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)for (j = 0; j < n; j++)a[i][j] = (i + 1) * 10 + j + 1;
    printf(" \n Source Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)printf("%3d", a[i][j]);
        printf("\n");
    }
    printf(" \n Result Vector:\n");
    i = 0;
    j = n - 1;
    for (k = 0; k < n * n; ++k) {
        printf("%3d", a[i][j]);
        i += di;
        j += dj;
        if ((i == -1 && j != -1) || (i == n)) {
            i -= di;
            j -= dj;
            j--;
            di = -di;
            dj = -dj;
        } else if ((j == -1 && i != -1) || (j == n) || (i == -1)) {
            i -= di;
            j -= dj;
            i++;
            di = -di;
            dj = -dj;
        }
    }
    return 0;
}




