#include <stdio.h>
#include <stdlib.h>
/*
 看点：
 程序肯定是有缺陷的：
    count 有点笨拙；
    输入的num是否在范围内需要检查吗？暂时不需要，和问题中的例子还是有区别的
    total 设置为unsigned 确实少了很多麻烦

    answer 理解错了，固定delta， realloc的过程
    当然这种realloc很笨拙
*/
int
main()
{
    unsigned int total;
    int *set;
    if (scanf("%u", &total)){
        set = malloc(total * sizeof(int));
        if (set == NULL) {
            exit(EXIT_FAILURE);
        }
    }
    int num;
    int count = 0;
    while( count < total && scanf("%d", &num) != EOF ){
        *(set + count) = num;
        count ++;
    }

    for (int i = 0; i < total; i++){
        printf("%d: %d\n", i, *(set + i));
    }
}