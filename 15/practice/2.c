#include <stdio.h>
# define BUFFSIZE 81
int
main()
{
    char buff[BUFFSIZE];
    while(fgets(buff, BUFFSIZE, stdin) != NULL) {
        fputs(buff, stdout);
    }
}
/*
    如果使用fgets，缓冲区长度至少为82字节，因为还需要存储一个换行符。
*/