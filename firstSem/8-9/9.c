#include <stdio.h>

int sign(int n) {
    if (n > 0) return 1;
    else if (n < 0) return -1;
    else return n;
}

int max(int n, int m) {
    if (n > m) return n;
    else return m;
}

int min(int n, int m) {
    if (n < m) return n;
    else return m;
}

int abs(int n) {
    if (n < 0) return -n;
    else return n;
}

int in_circle(int n, int m) {                //функция, проверяющая попадание точки в область
    if (((n + 10) * (n + 10) + (m + 10) * (m + 10) <= 100) && ((n + 20) * (n + 20) + (m + 20) * (m + 20) <= 100))
        return 1;
    else return 0;
}


int main() {
    const int i0 = -22, j0 = 29, l0 = 4;
    int i = i0, j = j0, l = l0, k, ii, jj, ll;
    for (k = 0; k < 50; k++) {
        if (in_circle(i, j)) {
            printf("point get\ntime k = %d\ncord i = %d\ncord j = %d\ndynamic l = %d\n", k, i, j,
                   l); //вывод если попала
            break;
        }
        ii = i;
        jj = j;
        ll = l;
        i = sign(min(ii, jj)) * max((ii + k) % 20, (jj + ll) % 20);
        j = abs(max(ii, jj)) - k * min(jj, ll);
        l = (k - ll) / ((ii + jj + ll) * (ii + jj + ll) % 5 + 1);

    }
    if (k == 50)
        printf("point doesn't get :(\ntime k = %d\ncord i = %d\ncord j = %d\ndynamic l = %d\n", k, i, j,
               l); //вывод если не попала
    return 0;
}
