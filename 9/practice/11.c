#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ANSWER
/*
    看点： 
        1. 令人糊涂的标准输入
        2. 库函数的使用
        3. 处理手法参考书本内容, 怎样写的更紧凑
        4. 改写成递归？

    答案： 使用“奇怪的函数strtok！”
*/

char	const	whitespace[] = " \n\r\f\t\v";

int
main()
{
    #ifndef ANSWER

    char line[100];
    char const substring[] = "the"; 
    register char *cur;
    int count;
    size_t sl;
    while(gets(line) != NULL){
        count = 0;
        // printf("debug %s\n", line);
        sl = strlen(line);
        cur = line;
        while(cur < line + sl){
            cur = strstr(cur, substring);
            if( cur == NULL ) break;
            count++;
            cur += 4;
        }
        printf("count: %d\n", count);
    }
    #else
    

    //answer
    char	buffer[101];
	int	count;

	count = 0;

	/*
	** Read lines until EOF is found.
	*/
	while( gets( buffer ) ){
		char	*word;

		/*
		** Extract words from the buffer one by one
		** until there are no more.
		*/
        int index = 0;
		for( word = strtok( buffer, whitespace);
		    word != NULL;
		    word = strtok( NULL, whitespace ) ){
                printf("index: %d, word: %s\n", index, word);
                index ++; 
			if( strcmp( word, "the" ) == 0 )
				count += 1;
		}
	}

	printf( "%d\n", count );

	return EXIT_SUCCESS;
    #endif
}