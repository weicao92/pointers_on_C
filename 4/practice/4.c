#include <stdio.h>
#include <string.h>

void 
copyn(char dst[], char src[], int n) {
    // answer： 不应用string.h里的strlen， 测试是src[i]否为0即可
    int src_len = strlen(src); 
    printf("debug: %d\n", src_len);   
    char cur;
    for (int i = 0; i < n; i++) {
        if(i >= src_len){
            cur = 0;
        }else{
            cur = src[i];
        }
        dst[i] = cur;
    }
}

int
main()
{
    char s1[100]  = "hellosdfasdfsd";
    char s2[200] = "ooooooooooooooooooooooooo";

    copyn(s2, s1, 177);
    printf("%s\n", s2);    
}