#include <stdio.h>

int
main() {
    int a = 0;
    int b = 3;
    printf("%lu\n", sizeof(a = b + 1 + 3)); //4
    printf("%d\n", a); //0
    printf("%d\n", b); //3
}