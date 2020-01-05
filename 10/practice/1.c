#include <stdio.h>
/*
    看点: 结构体内的指针
    answer的提示： 
    1.使用short和int 
    2.struct 名称大写
    3. triple number不用声明为struct，直接用数组，
    然后弄一个枚举类型，让数字下标有意义
    4. 声明为h： 头文件
*/
typedef struct
{
    char *district_num;
    char *exchange_num;
    char *station_num;
} phone_number;

typedef struct 
{
    phone_number *using;
    phone_number *calling;
    phone_number *paying;
}triple_number;

typedef struct 
{
    long datetime; //need confirm demand
    triple_number *triple;    
} longway_call;
