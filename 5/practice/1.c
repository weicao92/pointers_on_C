#include <stdio.h>

int
main()
{
    int c;
    while((c = getchar()) != EOF){
        if ( c >= 65 && c <= 92)
            c+=32;
        putchar(c);
    }
}   