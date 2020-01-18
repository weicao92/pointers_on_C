#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 512 
/*
    见fgrep.c： 写得更干净。抽提了函数，因为从标准输入读入本质上也是个FILE的处理。
*/
int
main(int argc, char**argv)
{
    FILE *input;
    int exit_status = EXIT_SUCCESS;
    char buf[MAX_BUF];
    char *str = *++argv;
    char *current;
    if(argc < 3){
       while(gets(buf) != NULL){
           current = strstr(buf, str);            
           if(current != NULL){
               printf("input line: %s\n", buf);
           }

       } 
        exit(exit_status);
    }
    while(*++argv!= NULL){
		input = fopen( *argv, "r" );
		if( input == NULL ){
			perror( *argv );
			exit_status = EXIT_FAILURE;
			continue;
		}
        while(fgets(buf, MAX_BUF, input) != NULL){
            current = strstr(buf, str);            
            if(current != NULL){
                printf("filename %s: %s", *argv, buf);
            }
        }
		if( fclose( input ) != 0 ){
			perror( "fclose" );
			exit( EXIT_FAILURE );
		}
    }
    exit(exit_status);
}