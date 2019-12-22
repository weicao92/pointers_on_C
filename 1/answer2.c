#include <stdio.h>
#include <stdlib.h>

int main(){
    int ch;
    int at_beginning = 1;
    int line = 0;

    while((ch = getchar())!= EOF){
        if (at_beginning){
            at_beginning = 0;

            line +=1;
            printf("%d.",  line );
        }
        putchar(ch);
        if(ch == '\n'){
            at_beginning = 1;
        }
    }

    return EXIT_SUCCESS;
}