#include <stdio.h>

int 
ascii_to_integer( char *string)
{
    int cur = 0;
    while(*string++ != '\0'){
        if(*string >= '0' && *string <= '9'){
            cur = cur * 10 + (*string - '0');
        }
    }
    /*
        与answer相比： 少了一步错误检查：
        遇到一个非数字字符而终止，把结果设为0？
        题目没有这样的表述啊！管他呢 不重要了我觉得
    */
    return cur;
}

int
main()
{
    char s[] = {'c','a','o','1', '0', 'w','e','i', '2', '\0'};
    printf("%d\n", ascii_to_integer(s));
}