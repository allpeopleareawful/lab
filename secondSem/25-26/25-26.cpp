#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "queueDynamic.h"
#include "queueMassive.h"

queue mergeSort(queue &q) {
    if (empty(q) || (size(q) == 1)) {
        return q;
    }
    queue tmp1, tmp2;
    init(tmp1);
    init(tmp2);
    int dim = size(q), split = 1;
    while (!empty(q)) {
        if (split <= dim / 2) {
            push(tmp1, pop(q));
            split++;
        } else push(tmp2, pop(q));
    }
    queue q1 = mergeSort(tmp1);
    queue q2 = mergeSort(tmp2);
    return merge(q1, q2);
}

int main() {
    srand(time(0));
    queue q;
    init(q);
    int in;
    while (1) {
        printf("Menu:\n"
               "1. Generate random queue\n"
               "2. Print queue\n"
               "3. Push value\n"
               "4. Pop value\n"
               "5. Sort queue\n"
               "0. Exit\n"
               "=> ");
        scanf("%d", &in);
        switch (in) {
            case 0: {
                return 0;
            }
            case 1: {
                printf("Please enter a size of queue:");
                scanf("%d", &in);
                while (in) {
                    push(q, rand() % 100);
                    in--;
                }
                break;
            }
            case 2: {
                display(q);
                break;
            }
            case 3: {
                printf("Please enter a value:");
                scanf("%d", &in);
                push(q, in);
                break;
            }
            case 4: {
                printf("%d\n", pop(q));
                break;
            }
            case 5: {
                q = mergeSort(q);
                break;
            }
        }
    }
}