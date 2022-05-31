#include <stdio.h>

#ifndef LAB_QUEUEMASSIVE_H
#define LAB_QUEUEMASSIVE_H
#define N 100;
typedef int typeValue;

struct queue {
    int start, end, size;
    typeValue value[N];
};

void init(queue &q) {
    q.start = q.size = 0;
    q.end = -1;
}

int empty(queue &q) {
    return q.size == 0;
}

void push(queue &q, typeValue v) {
    if (q.size == N) printf("Queue is overflow!\n")
    else {
        q.value[++q.end %= N] = v;
        q.size++;
    }
}

typeValue pop(queue &q) {
    if (!empty(q)) {
        q.size--;
        int i = q.start++;
        q.start %= N;
        return q.value[i];
    } else printf("Queue is empty!\n");
    return 0;
}

typeValue top(queue &q) {
    if (!empty(q)) return q.value[q.start];
    else printf("Queue is empty!\n");
    return 0;
}

int size(queue &q) {
    return q.size;
}

void display(queue q) {
    printf("[");
    for (int i = q.start; i < q.start + q.size; i++)
        printf("%d ", q.value[i % N]);
    printf("]\n");
}

queue merge(queue &q1, queue &q2) {
    queue q;
    init(q);
    while (!(empty(q1) && empty(q2))) {
        if (top(q1) < top(q2)) push(q, pop(q1));
        else push(q, pop(q2));
    }
    while (!empty(q1)) push(q, pop(q1));
    while (!empty(q2)) push(q, pop(q2));
    return q;
}

#endif //LAB_QUEUEMASSIVE_H
