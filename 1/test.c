#include<stdio.h>

int main(){
    // printf("hello, world!\n");
    char c;
    while(c = getchar() && c != 'c'){
        printf("%d",  c);
    }
}