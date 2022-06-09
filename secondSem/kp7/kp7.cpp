#include <stdio.h>
#include <stdlib.h>

void printShortMatrix(int *M, float *A, int cntLn, int cntNz) {
    printf("\nShort matrix\n");
    for (int i = 0; i < cntLn; ++i) {
        printf("%3d", M[i]);
    }
    printf("\n");
    for (int i = 0; i < 2 * cntNz; ++i) {
        printf("%2.1f ", A[i]);
    }
    printf("\n");
}

void printFullMatrix(float **matrix, int n, int m) {
    printf("\nFull matrix\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%2.1f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void task(float **matrix, int n, int m) {
    int maxNz = 0, nz = 0, colInd = 0, preCol = 0;
    float multiply = 1;

    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (matrix[i][j] != 0) {
                ++nz;
            }
        }
        if (nz >= maxNz) {
            if (nz == maxNz) {
                preCol = colInd;
            } else preCol = j;
            maxNz = nz;
            colInd = j;
        }
        nz = 0;
    }
    for (int i = 0; i < n; ++i) {
        multiply *= matrix[i][preCol];
    }
    printf("\nTask answer:\nmultiply: %2.2f\ncolumn: %d\n", multiply, preCol);
}

void shortToFull(float **matrix, int *M, float *A, int cntLn, int cntNz) {
    int start, end, cur, i, j, lastInd;
    for (i = 0; i < cntLn; ++i) {
        if (M[i] == 0) continue;
        start = M[i];
        lastInd = i - (1 * M[i] == 0);
        for (cur = i + 1; (cur < cntLn - 1) && (M[cur] == 0); ++cur);
        end = M[cur];
        for (j = start - 1; j < end - 1; ++j) {
            matrix[i][int(A[j])] = A[j + 1];
            ++j;
        }
    }
    //last pass
    for (j = M[lastInd]-1; j < 2 * cntNz; ++j) {
        matrix[lastInd][int(A[j])] = A[j + 1];
        ++j;
    }
}

void fullToShort(float **matrix, int *M, float *A, int cntNz, int n, int m) {
    for (int i = 0; i < n; ++i) {
        M[i] = 0;
    }
    for (int i = 0; i < cntNz * 2; ++i) {
        A[i] = 0;
    }
    int cnt = 0, zero = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] != 0) {
                if (!zero) {
                    M[i] = cnt + 1;
                    zero = 1;
                }
                A[cnt++] = j;
                A[cnt++] = matrix[i][j];
            }
        }
        zero = 0;
    }
}

int main() {
    float *A, **matrix;
    int *M, cntNz, n, m;

    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &cntNz);

    matrix = new float *[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new float[m];
    }
    M = new int[n];
    A = new float[3 * cntNz];

    for (int i = 0; i < n; ++i) {
        scanf("%d", &M[i]);
    }
    for (int i = 0; i < 2 * cntNz; ++i) {
        scanf("%f", &A[i]);
    }

    printShortMatrix(M, A, n, cntNz);
    shortToFull(matrix, M, A, n, cntNz);
    printFullMatrix(matrix, n, m);
    task(matrix, n, m);
    fullToShort(matrix, M, A, cntNz, n, m);
    printShortMatrix(M, A, n, cntNz);
    return 0;
}