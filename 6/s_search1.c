/*
** Given a pointer to a NULL-terminated list of pointers, search
** the strings in the list for a particular character.
*/

#include <stdio.h>
#include <stdio.h>

#define	TRUE	1
#define	FALSE	0

int
find_char( char **strings, char value )
{
	char	*string;	/* the string we're looking at */

	/*
	** For each string in the list ...
	*/
	while( ( string = *strings++ ) != NULL ){
        printf("debug strings: %u\n", strings);
		/*
		** Look at each character in the string to see if
		** it is the one we want.
		*/
		while( *string != '\0' ){
			if( *string++ == value ){
                printf("debug strings before return: %u\n", strings);
				return TRUE;
            }
		}
	}
    printf("debug strings before return: %u\n", strings);
	return FALSE;
}

int
find_char2( char **strings, int value )
{
	// assert( strings != NULL );

	/*
	** For each string in the list ...
	*/
	while( *strings != NULL ){
		/*
		** Look at each character in the string to see if
		** it is the one we want.
		*/
		while( **strings != '\0' ){
			if( *(*strings)++ == value )
				return TRUE;
		}
		strings++;
	}
	return FALSE;
}

int
main()
{
    char **strings = (char**)malloc(180 * sizeof(char *));
    char *string1 = "a"; 
    char *string2 = "b"; 
    char *string3 = "c"; 
    char *string4 = "d"; 
    char *string5 = "abcd";
    char *a_s[] = {string1, string2, string3, string4, string5, NULL}; 
    strings = &a_s; 
    printf("strings: %u\n", strings);
    int bool = find_char(strings, 'p');
    printf("result : %u\n", bool);
    printf("strings after: %u\n", strings);
    
}