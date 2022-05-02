#include <stdio.h>

int main() {
    int matrix[9][9], i, j, n, k;
    // Заполнение и вывод матрицы
    printf("Input matrix size \n");
    scanf("%d", &n);
    printf("Source matrix:\n");
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            matrix[i][j] = (i + 1) * 10 + j + 1;
            printf("%3d", matrix[i][j]);
        }
        printf("\n");
    }

    // Вывод матрицы зиг-загом (линеаризация)
    printf("Result vector:\n");
    for (k = 2 * n - 1; k > 0; --k) {
        if (k % 2) {                        // если k нечетное
            j = 2 * n - (2 * n - k);
            for (i = n; i >= 0; --i) {
                if (j < n && j >= 0 && i < n) printf("%3d", matrix[i][j]);
                --j;
            }
        } else {                              // если k четное
            j = n - (2 * n - k);
            for (i = 0; i < n; ++i) {
                if (j < n && j >= 0) printf("%3d", matrix[i][j]);
                ++j;
            }
        }
    } // цикл k
    return 0;
}
