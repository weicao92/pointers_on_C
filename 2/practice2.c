# include <stdio.h>
# include <stdlib.h>

int
main(void){
    int c;
    int in_string_literal = 0;
    int in_comment = 0;
    int is_slash = 0;
    int is_ast = 0;
    int  n_left = 0;
    while ( (c = getchar()) != EOF)
    {
        if(c == '*'){
            is_ast = 1;
            if ( is_slash == 1 &&  in_comment == 0) {
                in_comment = 1;
            }
            is_slash = 0;
            continue;
        }

        if (c == '/'){
            is_slash = 1;
            if (is_slash == 1 && in_comment == 1){
                in_comment = 0;
            }
            is_ast = 0;
            continue;
        }

        is_slash = 0;
        is_ast = 0;
        if ( c == '"'){
            in_string_literal = in_string_literal == 1? 0:1;
            continue;
        }

        if ( in_string_literal || in_comment){
            continue;
        }

        if (c == '{'){
            n_left ++;
            continue;
        }
        if (c == '}'){
            if( n_left == 0){
                return EXIT_FAILURE;
            }
            n_left --;
        }
    }
    if ( n_left == 0)
        return EXIT_SUCCESS;
    else
        return EXIT_FAILURE;

}