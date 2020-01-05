#include <stdio.h>

int
main()
{
    int a[] = {1,2,3,4};
    printf("a: %u\n", a);
    printf("&a: %u\n", &a);
    printf("a + 2: %u\n", a + 2);
    //&a 是整个数组的起始地址！！！ 
    printf("&(a) + 2: %u\n", (&a)+2 );

    int *p = a;
    printf("p: %u\n", p);
    printf("&p: %u\n", &p);//未知
}