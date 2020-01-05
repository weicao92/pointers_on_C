#include <stdio.h>
#include <string.h>
#include <stddef.h>

//对比答案发现：
size_t 
my_strlen(char *ch, size_t n)
{   
    register char *p = ch;
    while( *p++ != '\0' && p - ch <= n)
    ;
    return p - ch; //p - ch - 1
}

size_t 
my_strlen_revised(char *ch, size_t n)
{   
    register char *p = ch;
    while( *p != '\0' && ++p - ch < n)
        ;
    return p - ch; //p - ch - 1
}

//answer
size_t
my_strlen2( char const *string, int size )
{
	register size_t	length;

	for( length = 0; length < size; length += 1 )
		if( *string++ == '\0' )
			break;

	return length;
}

int
main()
{
    char ch[] = "hello world"; //length = 13
    printf("hello world: enough ori: %zu\n", my_strlen(ch, 100)); 
    printf("hello world: enough ans: %zu\n", my_strlen2(ch, 100));
    printf("hello world: enough rev: %zu\n", my_strlen_revised(ch, 100));
    printf("hello world: unenough ori: %zu\n", my_strlen(ch, 5));
    printf("hello world: unenough ans: %zu\n", my_strlen2(ch, 5));
    printf("hello world: unenough rev: %zu\n", my_strlen_revised(ch, 5));
}