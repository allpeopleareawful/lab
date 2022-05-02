#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, m, step, tmp, k, ans;
    printf("Input size of matrix (NxM)\n");
    scanf("%dx%d", &n, &m);
    int **matrix;
    int i = 0, j = 0;
    srand(time(0));
    matrix = new int *[n];
    for (i = 0; i < n; ++i) matrix[i] = new int[m];
    printf("\nMatrix:\n");
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            matrix[i][j] = rand() % 10;
            printf("%3d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nInput direction of the shitf (cols[0] rows[1])\n");
    scanf("%d", &ans);
    printf("Input step of the shift\n");
    scanf("%d", &step);
    if (ans == 0) { //сдвиг по столбцам
        for (i = 0; i < n; ++i) {
            for (k = 0; k < step; ++k) {
                tmp = matrix[i][0];
                for (j = 0; j < m - 1; ++j) matrix[i][j] = matrix[i][j + 1];
                matrix[i][m - 1] = tmp;
            }
        }
    } else {        //сдвиг по строкам
        for (j = 0; j < m; ++j) {
            for (k = 0; k < step; ++k) {
                tmp = matrix[0][j];
                for (i = 0; i < n - 1; ++i) matrix[i][j] = matrix[i + 1][j];
                matrix[n - 1][j] = tmp;
            }
        }
    }
    printf("\nResult matrix:\n");
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) printf("%3d", matrix[i][j]);
        printf("\n");
    }
    return 0;
}
