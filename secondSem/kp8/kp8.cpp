#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct list;
typedef list *link;
typedef float item;

struct list {
    item body;
    link prev, next;
} *base, *newElement, *lastElement, *current;

int length = 0, i, n;

void randomize() {
    long a = time(0);
    srand(a);
}

void add(item data) {
    if (!base) {
        base = new list;
        base->body = data;
        base->next = nullptr;
        base->prev = nullptr;
        lastElement = base;
    } else {
        newElement = new list;
        newElement->body = data;
        lastElement->next = newElement;
        newElement->next = nullptr;
        newElement->prev = lastElement;
        lastElement = newElement;
    }
    length++;
}

void addFirst(item data) {
    if (!base) {
        base = new list;
        base->body = data;
        base->next = nullptr;
        base->prev = nullptr;
        lastElement = base;
    } else {
        newElement = new list;
        newElement->body = data;
        newElement->next = base;
        newElement->prev = nullptr;
        base->prev = newElement;
        current = newElement;
        newElement = base;
        base = current;
    }
    length++;
}

void printList() {
    if (!base) {
        printf("\nList is empty\n");
    } else {
        current = base;
        printf("[ ");
        while (current) {
            if (current->next) { printf("%2.2f, ", current->body); }
            else { printf("%2.2f ", current->body); }
            current = current->next;
        }
        printf("]");
    }
    printf("\n");
}

void mainAction(int m) {
    for (i = 0; i < m; ++i) {
        addFirst(lastElement->body);
    }
}

int listLength() {
    return length;
}

void generateList(int n) {
    for (i = 0; i < n; ++i) {
        add(item(rand() % 10000) / 100);
    }
}

void insert(item m, item data) {
    if (!base) {
        printf("\nList is empty\n");
    } else {
        i = 0;
        current = base;
        while (current) {
            if (current->body == m) {
                newElement = new list;
                newElement->body = data;
                newElement->prev = current;
                newElement->next = current->next;
                current->next = newElement;
                i = 1;
                break;
            }
            current = current->next;
        }
    }
    if (!i) printf("Item with this value not exists!\n");
}

void deleteElement(item m) {
    i = 0;
    current = base;
    while (current) {
        if (current->body == m) {
            if (current == base) {
                base = base->next;
                delete current;
                i = 1;
                break;
            } else if (current == lastElement) {
                lastElement->prev->next = nullptr;
                lastElement = lastElement->prev;
                delete current;
                current = nullptr;
                i = 1;
                break;
            } else {
                newElement = current->next;
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                i = 1;
                break;
            }
        }
        current = current->next;
    }
    if (!i) printf("Item with this value not exists!\n");
}

void eraseList() {
    current = base;
    while (current) {
        newElement = current->next;
        delete current;
        current = newElement;
    }
    base = 0;
}

int main() {
    float m, m1;
    int k = 9;
    for (;;) {
        if (k == 9) {
            printf("\nInput from 1 to 10 or 0 for actions:\n"
                   "1. Generation list.\n"
                   "2. Addition new items in end of list.\n"
                   "3. Addition new items in begin of list.\n"
                   "4. Deleting from list.\n"
                   "5. Print list.\n"
                   "6. Inserting in list.\n"
                   "7. Erase list.\n"
                   "8. Lenght of list.\n"
                   "9. Print this MENU\n"
                   "10. Main Action\n"
                   "0. Exit out program.\n");
        }

        printf("\nInput number of MENU: ");
        scanf("%d", &k);

        if (!k) break;

        if (k == 1) {
            printf("\nInput number of new items of list: n = ");
            scanf("%d", &n);
            generateList(n);

        } else if (k == 2) {
            printf("\nInput value of adding item: m = ");
            scanf("%f", &m);
            add(m);

        } else if (k == 3) {
            printf("\nInput value of adding item: m = ");
            scanf("%f", &m);
            addFirst(m);

        } else if (k == 4) {
            scanf("%f", &m);
            deleteElement(m);

        } else if (k == 5) printList();

        else if (k == 6) {

            printf("\nInput value inserting item = ");
            scanf("%f", &m);
            printf("\nInput value item after which to insert = ");
            scanf("%f", &m1);
            insert(m, m1);

        } else if (k == 7) eraseList();

        else if (k == 8) {
            printf("\nLenght of list = %d\n", listLength());

        } else if (k == 10) {
            if (!base) {
                printf("\nList is empty!\n");
                continue;
            }

            printf("\nInput value for main action = ");
            scanf("%d", &n);
            mainAction(n);

        } else if (k > 10) printf("Have no such number of MENU\n");
    }

    return 0;
}