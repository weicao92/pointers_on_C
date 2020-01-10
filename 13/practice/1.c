#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*
本期看点直接看答案。
*/
int is_not_print( int ch )
{
	return !isprint( ch );
}

//answer： jump table！！！函数指针数组
static	int	(*test_func[])( int ) = {
	iscntrl,
	isspace,
	isdigit,
	islower,
	isupper,
	ispunct,
	is_not_print
};
#define	N_CATEGORIES	\
	    ( sizeof( test_func ) / sizeof( test_func[ 0 ] ) )


char	*label[] = {
	"control",
	"whitespace",
	"digit",
	"lower case",
	"upper case",
	"punctuation",
	"non-printable"
};

int	count[ N_CATEGORIES ];
int	total;

int
main()
{
	int	ch;
	int	category;

	/*
	** Read and process each character
	*/
	while( (ch = getchar()) != EOF ){
		total += 1;

		/*
		** Call each of the test functions with this
		** character; if true, increment the associated
		** counter.
		*/
		for( category = 0; category < N_CATEGORIES;
		    category += 1 ){
			if( test_func[ category ]( ch ) )
				count[ category ] += 1;
		}
	}

	/*
	** Print the results.
	*/
	if( total == 0 ){
		printf( "No characters in the input!\n" );
	}
	else {
		for( category = 0; category < N_CATEGORIES;
		    category += 1 ){
			printf( "%3.0f%% %s characters\n",
			    count[ category ] * 100.0 / total,
			    label[ category ] );
		}
	}

	return EXIT_SUCCESS;
}