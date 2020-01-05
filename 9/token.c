/*
** Extract whitespace-delimited tokens from a character array and
** print them one per line.
*/
#include <stdio.h>
#include <string.h>

void
print_tokens( char *line )
{
	static	char	whitespace[] = " \t\f\r\v\n";
	char	*token;

	for( token = strtok( line, whitespace );
	    token != NULL;
	    token = strtok( NULL, whitespace ) )
		printf( "Next token is %s\n", token );
}

int 
main()
{
	char line[] = "hello, world a b c d e weicao";
	print_tokens(line);
	/*
		Next token is hello,
		Next token is world
		Next token is a
		Next token is b
		Next token is c
		Next token is d
		Next token is e
		Next token is weicao
	*/
}

