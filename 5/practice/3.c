#include <stdio.h>
/*
    答案的更加聪明，而且不用考虑循环机器字长，增加了可移植性。
*/

unsigned int 
reverse_bits(unsigned int value)
{
    const int bits_num = sizeof(unsigned int) * 8;
    
    unsigned int answer = 0;
    int mask;
    int flag;
    for(int i = 0; i < bits_num; i++) {
        mask = 1 << i;
        flag = (value & mask) > 0;
        answer |= (  flag << (bits_num - i - 1));
    }
    return answer;
}

int
main()
{
    unsigned int t = 25;
    printf("%u\n", reverse_bits(t));
}