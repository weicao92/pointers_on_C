#include <stdio.h>

int
main()
{
    int c = 112;
    

    double prev;
    double post = 1;
    int step = 0;
    while(prev = post, post = (prev + c/prev)/2, step++ , post != prev && step <= 10000000)
        ;

    printf("%lf\n", prev);
    printf("%lf\n", post);
    printf("%d\n", step); //9 
    
}
