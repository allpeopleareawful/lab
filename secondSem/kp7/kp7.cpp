#include <stdio.h>
#include <stdlib.h>

void printShortMatrix(int *M, float *A, int cntLn, int cntNz) {
    printf("Short matrix\n");
    for (int i = 0; i < cntLn; ++i) {
        printf("%3d", M[i]);
    }
    printf("\n");
    for (int i = 0; i < 2 * cntNz; ++i) {
        printf("%2.1f ", A[i]);
    }
}

void printFullMatrix(float **matrix, int n, int m) {
    printf("\nFull matrix\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%2.1f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void task(float **matrix, int n, int m) {
    int maxNz = 0, nz = 0, colInd = 0, preCol = 0;
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
    nz = 1;
    for (int i = 0; i < n; ++i) {
        nz *= matrix[i][preCol];
    }
    printf("\nTask answer:\nmultiply: %d\ncolumn: %d\n", nz, preCol);
}

void shortToFull(float **matrix, int *M, float *A, int cntLn, int cntNz) {
    int start, end, ln = 0;
    for (ln = 0; ln < cntLn - 1; ++ln) {
        start = M[ln];
        end = M[ln + 1];
        for (int j = start; j < end; ++j) {
            matrix[ln][int(A[j])] = A[j + 1];
            ++j;
        }
    }
    //last pass
    for (int j = end; j < 2 * cntNz; ++j) {
        matrix[ln][int(A[j])] = A[j + 1];
        ++j;
    }
}

void fullToShort(float **matrix, int *M, float *A, int n, int m) {
    int cnt = 0, zero = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] != 0) {
                if (!zero) {
                    M[i] = cnt;
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

    //printf("Enter n\n");
    scanf("%d", &n);
    //printf("Enter m\n");
    scanf("%d", &m);
    //printf("Enter cntNz\n");
    scanf("%d", &cntNz);

    matrix = new float *[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new float[m];
    }
    M = new int[n];
    A = new float[3 * cntNz];

    //printf("Enter short matrix\n");
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
    return 0;
}