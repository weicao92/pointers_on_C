#include <stdio.h>

int
main(){
    // EOF = -1
    unsigned char a = '\377';//\377 -> 255 有符号字符集解释为-1
    unsigned short b = '\377';
    short c = '\377';
    int d = '\377';
    printf("%u\n", a); //255
    printf("%d\n", a);//255 
    printf("%u\n", b);//65535
    printf("%d\n", b);//65535
    printf("%u\n", c);//429....
    printf("%d\n", c);//-1  
    printf("%lu\n", sizeof(c));
    printf("%u\n", d);//429....
    printf("%d\n", d);//-1  
    printf("%lu\n", sizeof(d));
    printf("-----\n");
    printf("%d\n", a == EOF); //0 always false
    printf("%d\n", b == EOF); //0 always false
    printf("%d\n", c == EOF); //1
    printf("%d\n", d == EOF); //1
    /*
    运行在无符号字符集的机器上 是什么意思
    */
}