#include <stdio.h>
/*
大体没错，但是一些技巧需要结合课本学习：
比如：
register int 
没有必要申请sum，**就地**的指针运算
记住运用指针间接访问而不是下标
!!! 复习～～
*/
int pair_to_index(int x, int y, int col)
{
    return x * col + y;
}

void 
matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z)
{   
 int cur, sum;
 //x,y * y,z ==> x,z
 for(int i = 0; i < x; i++){
     for(int j = 0; j < z; j++){
         sum = 0;
         for(cur = 0; cur < y; cur++){
             sum += m1[pair_to_index(i, cur, y)] * m2[pair_to_index(cur, j, z)];
         }
         r[pair_to_index(i,j,z)] = sum;
     }
 }       
}

int
main()
{
    int x = 3;
    int y = 2;
    int z = 4;
    int m1[] = {2, -6, 3, 5, 1, -1};
    int m2[] = {4, -2, -4, -5, -7, -3, 6, 7};
    int r[12];
    matrix_multiply(m1, m2, r, x, y, z);
    for(int *p = r; p < r + 12; p++){
        printf("%d\n", *p);
    }
}