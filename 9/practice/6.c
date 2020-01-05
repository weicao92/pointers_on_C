#include <stdio.h>

char *
my_strcpy_end( char *dst, char const *src)
{
    while(*src != '\0'){
        // printf("debug *src: %c\n", *src);
        // printf("debug *dst: %c\n", *dst);
        *dst++ = *src++;
    }
    *dst = '\0';
    return dst;
}

char *
my_strcpy_end2( register char *dst, register char const *src )
{
	while( ( *dst++ = *src++ ) != '\0' )
		;

	return dst - 1;
}

int
main()
{
    char a[] = "hello message";
    char b[] = "different";
    char *end = my_strcpy_end(a, b);
    printf("a: %s\n", a);
    printf("diff %d\n", end - a);
    printf("end: %u\n", end);
    char *end2 = my_strcpy_end2(a, b);
    printf("a: %s\n", a);
    printf("diff %d\n", end2 - a);
    printf("end: %u\n", end2);

}