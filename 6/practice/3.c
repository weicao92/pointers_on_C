#include <stdio.h>

void 
reverse_string(char *string)
{
    // step 1: find strlen, extract to function?
    char *start = string;
    unsigned int strlen = 0;
    while(*start++ != '\0'){
        strlen++;
    }
    start = string;

    //step 2: reverse
    char *end = start + (strlen - 1);
    char tmp;
    char tmp2;
    while(end > start) {
        tmp = *start;
        tmp2 = *end; 
        *start = tmp2;
        *end = tmp;
        start++;
        end--;
    }
}
/*
** Reverse the string contained in the argument.
*/

void
reverse_string2( char *str )
{
	char	*last_char;

	/*
	** Set last_char to point to the last character in the
	** string.
	*/
	for( last_char = str; *last_char != '\0'; last_char++ )
		;

	last_char--;

	/*
	** Interchange the characters that str and last_char point
	** to, advance str and move last_char back one, and keep
	** doing this until the two pointers meet or cross.
	*/
	while( str < last_char ){
		char	temp;

		temp = *str;
		*str++ = *last_char;
		*last_char-- = temp;
	}
}

int
main()
{
    char s[] = {'c','a','o','w','e','i', '\0'};
    char *string = &s[0];
    reverse_string(string);
    printf("%s\n", string);
}