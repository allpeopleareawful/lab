#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sortFlag = 0, printFlag = 0;

struct row {
    float key;
    char *string;
};

int getSize(FILE *f) {
    int size = 0;
    char *buffer = new char[128];
    size_t l = sizeof(buffer);
    while (!feof(f)) {
        getline(&buffer, &l, f);
        size++;
    }
    delete[] buffer;
    rewind(f);
    return size;
}

float last;
void printTable(row *table, int size) {
    printf("-----------------------------------------------------------\n");
    printf("| Key |                       Data                        |\n");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < size; ++i) {
        printf("|%f | %s", table[i].key, table[i].string);
        if ((last == table[i].key) && ((printFlag == 1))) printf("\n");
        if ((i == (size - 1)) && (printFlag == 0)) {
            last = table[i].key;
            printFlag = 1;
            printf("\n");
        }
        printf("-----------------------------------------------------------\n");
    }
    printf("\n");
}

row *makeTable(FILE *keys, FILE *value, int size) {
    row *table = new row[size];
    for (int i = 0; i < size; ++i) {
        table[i].string = new char[128];
    }
    for (int i = 0; i < size; ++i) {
        fscanf(keys, "%f", &table[i].key);
        fgets(table[i].string, 128, value);
    }
    return table;
}

int binSearch(row *tab, float key, int size) {
    int l = 0, r = size - 1, mid;
    while (l <= r) {
        mid = (r + l) / 2;
        if (key == tab[mid].key) return mid;
        else if (key < tab[mid].key) r = mid;
        else if (key > tab[mid].key) l = mid + 1;
    }
    return -1;
}

void swapStrings(row *table, int a, int b) {
    row tmp;
    tmp = table[a];
    table[a] = table[b];
    table[b] = tmp;
}

void mixTable(row *tab, int size) {
    sortFlag = 0;
    int a, b;
    for (int i = 0; i < size; ++i) {
        a = rand() % size;
        b = rand() % size;
        swapStrings(tab, a, b);
    }
}

void reverseStrings(row *table, int size) {
    sortFlag = 0;
    for (int i = 0, j = size - 1; i < j; ++i, --j) swapStrings(table, i, j);
}

void sift(row *tab, int i, int bot) {
    int max;
    int flag = 0;
    while ((i * 2 <= bot) && (!flag)) {
        if (i * 2 == bot) max = i * 2;
        else if (tab[i * 2].key > tab[i * 2 + 1].key) max = i * 2;
        else max = i * 2 + 1;
        if (tab[i].key < tab[max].key) {
            swapStrings(tab, i, max);
            i = max;
        } else flag = 1;
    }
}

void heapSort(row *tab, int size) {
    for (int i = size / 2; i >= 0; --i) {
        sift(tab, i, size - 1);
    }
    for (int i = size - 1; i >= 1; --i) {
        swapStrings(tab, 0, i);
        sift(tab, 0, i - 1);
    }
}

void sortTable(row *tab, int size) {
    sortFlag = 1;
    heapSort(tab, size);
}

int main() {
    srand(time(0));
    FILE *firstFile = fopen("IN1", "r");
    if (firstFile == NULL) {
        printf("Can not open file 1\n");
        return 0;
    }
    FILE *secondFile = fopen("IN2", "r");
    if (secondFile == NULL) {
        printf("Can not open file 2\n");
        return 0;
    }
    int n = getSize(firstFile), action;
    row *tab = makeTable(firstFile, secondFile, n);
    fclose(firstFile);
    fclose(secondFile);
    printTable(tab, n);
    while (true) {
        printf("Menu\n"
               "1. Print table\n"
               "2. Mix table\n"
               "3. Reverse table\n"
               "4. Binary search\n"
               "5. Sort table\n"
               "0. Exit\n"
               "Choose an action =>");
        scanf("%d", &action);

        switch (action) {
            case 1: {
                printTable(tab, n);
                break;
            }
            case 2: {
                mixTable(tab, n);
                break;
            }
            case 3: {
                reverseStrings(tab, n);
                break;

            }
            case 4: {
                if (sortFlag) {
                    printf("Enter the key: ");
                    float key;
                    scanf("%f", &key);
                    int search;
                    printf("\n");
                    search = binSearch(tab, key, n);
                    if (search == -1) {
                        printf("Element with such key is not found!\n");
                        break;
                    }
                    printf("Found the string:\n %s", tab[search].string);
                } else
                    printf("Table is not sorted!\n");
                break;
            }
            case 5: {
                sortTable(tab, n);
                break;
            }
        }
    }
}


