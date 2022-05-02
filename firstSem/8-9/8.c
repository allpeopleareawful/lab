#include <stdio.h>

void func() {
    return 5;
}

int func1() {
    return "test";
}

int main() {
    int i, n = 10;
    for (i = 0; i < 10; i++) printf("%d\n", i / 0);
    func();
    func1();

    return 0
}
