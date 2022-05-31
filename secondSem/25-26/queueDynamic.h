#include <stdio.h>
#ifndef LAB_QUEUEDYNAMIC_H
#define LAB_QUEUEDYNAMIC_H
#define N 100
typedef int typeValue;

struct element {
    element *next;
    typeValue value;
};

struct queue {
    element *start;
    element *end;
    int size;
};

void init(queue &q) {
    q.start = 0;
    q.end = 0;
    q.size = 0;
}

int empty(queue &q) {
    return q.start == 0;
}

void push(queue &q, typeValue value) {
    if (q.size == N) {
        printf("Queue is overflow!\n");
        return;
    } else if (empty(q)) {
        q.end = new element;
        q.end->value = value;
        q.start = q.end;
    } else {
        element *tmp = new element;
        q.end->next = tmp;
        tmp->value = value;
        q.end = tmp;
        q.end->next = 0;
    }
    q.size++;
}

typeValue pop(queue &q) {
    if (!empty(q)) {
        typeValue value = q.start->value;
        q.start = q.start->next;
        q.size--;
        return value;
    } else printf("Queue is empty!\n");
    return 0;
}

typeValue top(queue &q) {
    if (!empty(q)) return q.start->value;
    else printf("Queue is empty!\n");
    return 0;
}

int size(queue &q) {
    return q.size;
}

void display(queue &q) {
    if (!empty(q)) {
        element *tmp = q.start;
        printf("[");
        while (tmp) {
            printf("%d ", tmp->value);
            tmp = tmp->next;
        }
        printf("]\n");
    } else printf("Queue is empty!\n");
}

queue merge(queue &q1, queue &q2) {
    queue q;
    init(q);
    while (!(empty(q1) || empty(q2))) {
        if (top(q1) < top(q2)) push(q, pop(q1));
        else push(q, pop(q2));
    }
    while (!empty(q1)) push(q, pop(q1));
    while (!empty(q2)) push(q, pop(q2));
    return q;
}

#endif //LAB_QUEUEDYNAMIC_H
