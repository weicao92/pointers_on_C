#include <stdio.h>

int 
main(){
    // 抽提出函数最佳
    int year;
    year = 2000;
    int leap = 0;
    if ((year % 4 == 0 && year % 100 != 0)
    || year % 400 == 0){
        leap = 1;
    }
    printf("leap_year? %d\n", leap);
       
}